/*
 * Juliano Nguyen
 * 4/12/2016
 * CSS162 - Bill Money Date assignment
 * Driver - Simple driver to test Money, Date, and Bill classes
 */
public class BillMoneyDateDriver {

    /**
    main driver function
    pre:  none
    post: exercises the methods in Bill, Money, and Date
    */
   public static void main(String[] args)
   {
       moneyTest(); //calls method to test Money class
       dateTest(); //calls method to test Date class
       billTest(); //calls method to test Bill class
   }
   
   /*
    * Tests Bill class
    * Create new Bill objects, use getters/setters, equals, call other classes
    */
   public static void billTest()
   {
       //Construct some bills
       Money amount = new Money(20);
       Date dueDate = new Date(4, 30, 2014);
       Bill bill1 = new Bill(amount, dueDate, "The phone company"); //20.00, 4/30/2014
      
       Bill bill2 = new Bill(bill1);
       bill2.setDueDate(new Date(5, 30, 2014)); //changes date for bill2
       amount.setMoney(31, 99);
       dueDate.setDay(29);
       
       //testing bill2 setPaid
       bill2.setPaid(new Date(5,29,2014));
       //bill2.setPaid(new Date(5,31,2014)); //day after due date
       //bill2.setPaid(new Date(6,30,2014)); // month after due date
       //bill2.setPaid(new Date(5,30,2015)); //year date after due date
       
       dueDate.setYear(2015);
       Bill bill3 = new Bill(amount, dueDate, "The record company"); //31.99, 4/29/2014
       
       //testing bill3 setDueDate
       bill3.setPaid(new Date(4,20,2015));
       //bill3.setDueDate(new Date(4,20,2015));
       //bill3.setDueDate(new Date(4,19,2015)); //day before paid date
       //bill3.setDueDate(new Date(3,20,2015)); //month before paid date
       //bill3.setDueDate(new Date(4,20,2014)); //year before due date
       
       Bill bill4 = new Bill(bill3);       
       Bill bill5 = new Bill();
       
       //prints out bill (paid, amount, due date, originator, paid date)
       System.out.println("Bill objects output:");
       System.out.println("bill1: " + bill1);
       System.out.println("bill2: " + bill2);
       System.out.println("bill3: " + bill3);
       System.out.println("bill4: " + bill4);
       System.out.println("bill5: " + bill5);
       
       //prints out if two bills are equal or not
       System.out.println("bill1 equals bill1? " + bill1.equals(bill1));
       System.out.println("bill1 equals bill2? " + bill1.equals(bill2));
       System.out.println("bill1 equals bill3? " + bill1.equals(bill3));
       System.out.println("bill3 equals bill4? " + bill3.equals(bill4));
       System.out.println("bill4 equals bill5? " + bill4.equals(bill5));
       
       System.out.println("bill1 compareTo bill1: " + bill1.compareTo(bill1));
       System.out.println("bill1 compareTo bill2: " + bill1.compareTo(bill2));
       System.out.println("bill1 compareTo bill3: " + bill1.compareTo(bill3));
       System.out.println("bill1 compareTo bill5: " + bill1.compareTo(bill5));
       
       //change bill5 to be same as bill4
       bill5.setAmount(bill4.getAmount());
       bill5.setOriginator(bill4.getOriginator());
       bill5.setDueDate(bill4.getDueDate());
       bill5.setPaid(new Date(4,20,2015));
       
       System.out.println("bill5 AFTER: " + bill5);
       System.out.println("bill4 equals bill5? " + bill4.equals(bill5));
   }
   
   /*
    * Tests Date class
    * Create new Date objects, use getters/setters, equals
    */
   public static void dateTest()
   {
	   Date date1 = new Date(); // 1/1/2014
	   Date date2 = new Date(2,20,2015);
	   Date date3 = new Date(date2);
	   
	   date1.setYear(2016);
	   date1.setMonth(4);
	   date1.setDay(2);
	   
	   //prints out dates
	   System.out.println(date1);
	   System.out.println(date2);
	   System.out.println(date3);
	   
	   //tests if two dates are equal
	   System.out.println("date1 equals date2? " + date1.equals(date2));
	   System.out.println("date2 equals date3? " + date2.equals(date3));
	   
   }
   
   /*
    * Tests Money class
    * Create new Money objects, use getters/setters, equals, add
    */
   public static void moneyTest()
   {
	 //Construct some money
       Money money1 = new Money(10);
       Money money2 = new Money(money1);
       money1.setMoney(30,50);
       //TODO: do more functional exercises with the money class
       
       System.out.println("Money objects output:");
       System.out.println("Money1: " + money1); //30.50
       System.out.println("Money2: " + money2); //10.00
       System.out.println(money1.getMoney());
       
       //Money money3 = new Money(2,-1); //negative cents
       //Money money4 = new Money(-1); //negative dollars
       Money money5 = new Money(money2);
       
       System.out.println("Money5 before: " + money5); //10.00
       System.out.println("money1 equals money2? " + money1.equals(money2)); //equals method
       System.out.println("money2 equals money5? " + money2.equals(money5));
       
       money5.setDollars(20);
       money5.setCents(99);
       
       //add dollars/cents/money to a Money object
       System.out.println("Money5 after: " + money5); //20.99
       money5.add(2, 40);
       System.out.println("money5 with added dollars/cents: " + money5); //23.39
       
       money1.add(5);
       //money1.add(-10); //add negative = subtracting if total money is not negative
       System.out.println("money1 with added dollars: " + money1);
       money2.add(money1);
       System.out.println("money2 with added money1: " + money2);
       
       Money money6 = new Money(5,101); //6.01       
       System.out.println("Money6: " + money6);
   }
}
