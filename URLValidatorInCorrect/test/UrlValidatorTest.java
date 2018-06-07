

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
      int counter = 10;
      int num_bugs = 0;

      //arrays of each valid parts of URL 
      String[] valid_schemes    = { "http://", "ftp://", "h3t://", ""}; 
      String[] valid_authority  = { "www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com"}; 
      String[] valid_ports      = { ":80", ":65535", ":0", "" }; 
      String[] valid_path       = { "/test1", "/t123", "/$23", "/test1/", "", "/test1/file" }; 
      String[] valid_queries    = { "?action=view", "?action=edit&mode=up", "" };

      //to store failed URL
      String[] failed_url = new String[counter];
      int failed_index = 0;

      for(int i = 0; i < counter; i++){
         //create random valid parts of URL
         int random_schemes = (int) (Math.random() * 3);
         int random_authority = (int) (Math.random() * 5);
         int random_ports = (int) (Math.random() * 3);
         int random_path = (int) (Math.random() * 5);
         int random_queries = (int) (Math.random() * 2);

         //each URL component is randomly selected from the array in the proper order to form a valid address
         String test_url = schemes[random_schemes] + authority[random_authority] + ports[random_ports] + path[random_path] + queries[random_queries];

         //check if the created test_url is valid
         UrlValidator validator = new UrlValidator();
         boolean assertion = validator.isValid(test_url);

         if(assertion == false){
            num_bugs++; //increment number of bugs
            failed_url[failed_index] = test_url; //store failed url
            failed_index++;   //increment failed counter
         } else {
            System.out.println ("Pass! No bugs were found.");
         }
      }

      //print out number of bugs and failed URLs which caused bugs
      System.out.println("Number of bugs we found: " + num_bugs + "\n");
      System.out.println("Failed URLs: \n");
      for ( int m = 0; m < failed_url.length; m++) {
         if ( failed_url[m] != null ) {
            System.out.println( failed_url[m] + "\n");
         } else {
            System.out.println( "None \n");
         }
      }
   }
   


}
