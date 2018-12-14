using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using Accord.Audio.Formats;
using Accord.Audio;
using Accord.Math;
using Accord.Audio.Windows;

namespace Assignement4Audio
{
    class AudioFeatures
    {
        private string[] audioFileName;

        public void SetDirectoryPaths(string folderPath)
        {
            audioFileName = Directory.GetFiles(folderPath, "*.wav").Select(Path.GetFileName).OrderBy(r => r.Length).ToArray();

            for (int i = 0; i < audioFileName.Length; i++)
            {
                string fileName = audioFileName[i];
                WaveDecoder sourceWD = new WaveDecoder(fileName);
                Signal sourceS = sourceWD.Decode();

                RaisedCosineWindow window = RaisedCosineWindow.Hamming(1024);
                Signal[] windows = sourceS.Split(window, 512);

                ComplexSignal[] complex = windows.Apply(ComplexSignal.FromSignal);

                complex.ForwardFourierTransform();
            }
        }

        public void waveInput()
        {
            writeHeaderForARFF();
            for (int i = 0; i < audioFileName.Length; i++)
            {
                string type;
                string name;
                setTypeAndName(audioFileName[i], out type, out name);
                

                Accord.Audio.Formats.WaveDecoder currentWav = new Accord.Audio.Formats.WaveDecoder(audioFileName[i]);
                //Used for time Domain
                Signal timeDomain = currentWav.Decode();


                //Creates an array of time domain samples for use in calculation of RootMeanSquare aka AverageEnergy
                float[] energyArray = new float[timeDomain.Samples];
                timeDomain.CopyTo(energyArray);

                //average energy for the current wav file
                double averageEnergy = Accord.Audio.Tools.RootMeanSquare(energyArray);
                //ZCR for the current wav file
                double zeroCrossingRate = zeroCrossingRateMethod(timeDomain);

                Accord.Audio.Windows.RaisedCosineWindow window = Accord.Audio.Windows.RaisedCosineWindow.Hamming(1024);
                Signal[] windows = timeDomain.Split(window, 512);
                //Used for Frequency Domain
                ComplexSignal[] tempFrequency = windows.Apply(ComplexSignal.FromSignal);
                tempFrequency.ForwardFourierTransform();
                ComplexSignal curComplex = tempFrequency[0];

                double[] power = { };
                double[] magnitudes = { };
                double[] freq = { };
                var length = curComplex.Length / (2 + 1);
                double[] meanPower = new double[length];
                double[] meanMagnitudes = new double[length];

                createFrequencyArray(tempFrequency, curComplex, out power, out magnitudes, out freq, out meanPower, out meanMagnitudes);


                //Spectral Centrois for the current wav file
                double spectralCentroid = meanMagnitudes.Zip(freq, (m, f) => m * f).Sum() / meanMagnitudes.Sum();
                //double spectralCentroid = spectralCentroidMethod(tempFrequency);

                //Writes data to arff file
                writeARFF(name, averageEnergy, zeroCrossingRate, spectralCentroid, type);
            }
        }

        // get the type and name of the file
        private void setTypeAndName(string audioFileName, out string type, out string name)
        {
            if (audioFileName.Contains("mu"))
            {
                type = "MUSIC";
                name = Path.GetFileName(audioFileName);
            }
            else
            {
                type = "SPEECH";
                name = Path.GetFileName(audioFileName);
            }
        }

        //Computes the Zero Corssing Rate
        public double zeroCrossingRateMethod(Signal currentSignal)
        {
            double[] zcrArray = currentSignal.ToDouble();
            int zeroCrosssings = 0;

            for (int i = 0; i < zcrArray.Length - 1; i++)
            {
                if ((zcrArray[i] >= 0 && zcrArray[i + 1] < 0) || (zcrArray[i] < 0 && zcrArray[i + 1] >= 0))
                {
                    zeroCrosssings++;
                }

            }
            return zeroCrosssings / (2.0 * (currentSignal.Samples - 1));
        }

        public void writeARFF(string name, double energy, double zcr, double sCent, string type)
        {
            using (StreamWriter temp = new StreamWriter("AudioFeatures.arff", true, System.Text.Encoding.ASCII))
            {
                temp.WriteLine(name + "," + energy.ToString() + "," + zcr.ToString() + "," + sCent.ToString() + "," + type);
            }
        }
        //Writes the ARFF file header
        public void writeHeaderForARFF()
        {
            File.WriteAllText("AudioFeatures.arff", string.Empty);
            using (StreamWriter temp = new StreamWriter("AudioFeatures.arff", true, System.Text.Encoding.ASCII))
            {
                temp.WriteLine("@RELATION    audioAssignment");
                temp.WriteLine();
                temp.WriteLine("@ATTRIBUTE   \"File Name\"   STRING");
                temp.WriteLine("@ATTRIBUTE   \"Average Energy\"  REAL");
                temp.WriteLine("@ATTRIBUTE   \"Zero Crossing Rate\"  REAL");
                temp.WriteLine("@ATTRIBUTE   \"Spectral Centroid\"   REAL");
                temp.WriteLine("@ATTRIBUTE   \"Audio Type\"  {MUSIC, SPEECH}");
                temp.WriteLine();
                temp.WriteLine("@DATA");
            }
        }

        public void frequencyData(ComplexSignal curSig, out double[] powers, out double[] magnitudes, out double[] freq)
        {
            powers = Accord.Audio.Tools.GetPowerSpectrum(curSig.GetChannel(0));
            magnitudes = Accord.Audio.Tools.GetMagnitudeSpectrum(curSig.GetChannel(0));
            freq = Accord.Audio.Tools.GetFrequencyVector(curSig.Length, curSig.SampleRate);
        }

        public void createFrequencyArray(ComplexSignal[] tempFrequency, ComplexSignal curComplex, out double[] power, out double[] magnitudes, out double[] freq, out double[] meanPower, out double[] meanMagnitudes)
        {
            int amountOfSignals = 0;
            var length = curComplex.Length / (2 + 1);
            double[] tempMeanPower = new double[length];
            double[] tempMeanMag = new double[length];
            double[] tempPower = { };
            double[] tempMagnitudes = { };
            double[] tempFreq = { };

            foreach (ComplexSignal curSig in tempFrequency)
            {
                frequencyData(curSig, out tempPower, out tempMagnitudes, out tempFreq);
                for (int j = 0; j < length; j++)
                {
                    tempMeanPower[j] += tempPower[j];
                    tempMeanMag[j] += tempPower[j];
                }
                amountOfSignals++;
            }
            for (int j = 0; j < length; j++)
            {
                tempMeanPower[j] /= amountOfSignals;
                tempMeanMag[j] /= amountOfSignals;
            }
            meanPower = tempMeanPower;
            meanMagnitudes = tempMeanMag;
            power = tempPower;
            magnitudes = tempMagnitudes;
            freq = tempFreq;
        }
    }
}
