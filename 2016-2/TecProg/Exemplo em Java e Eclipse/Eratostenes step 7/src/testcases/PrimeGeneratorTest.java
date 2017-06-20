package testcases;

/**
 * Test the PrimeNumbersGenerator class using JUnit test cases.
 * 
 */

import eratostenes.InvalidMaxNumberException;
import eratostenes.PrimeGenerator;
import junit.framework.TestCase;

/**
 * Unit test cases to test the PrimeNumbersGenerator class.
 * 
 */
public class PrimeGeneratorTest extends TestCase {

	// generator instance for all tests.
	private PrimeGenerator primeGenerator = new PrimeGenerator();
	
	// Tests the first prime number.
	public void testPrimeToTwo() throws Exception {
		verifyGeneratedPrime("2", 2);
	}

	// Tests two prime numbers.
	public void testPrimeNumbersToThree() throws Exception {
		verifyGeneratedPrime("2, 3", 3);
	}
	
	//
	public void testPrimeNumbersToFour() throws Exception {
		verifyGeneratedPrime("2, 3", 4);
	}
	
	// Tests invalid max number: 1.
    public void testMaxNumberOne() throws Exception {
    	verifyInvalidMaxNumberRejected(1);  
    }  

    // Tests invalid max number: 0.
    public void testMaxNumberZero() {  
    	verifyInvalidMaxNumberRejected(0);  
    }  
    
    // Tests invalid max number: -100.
    public void testMaxNumberNegative() {  
    	verifyInvalidMaxNumberRejected(-100);  
    }
    
	// Verifies if the returned prime string matches the expected string.
	private void verifyGeneratedPrime(String expectedList, int max)
			throws Exception {
		assertEquals(expectedList, primeGenerator.generatePrimeTo(max));
	}
	
	private void verifyInvalidMaxNumberRejected(int maxNumber) {  
	    try {  
	    	primeGenerator.generatePrimeTo(maxNumber);  
	        fail("Should have throw InvalidMaxNumberException");  
	    } catch (InvalidMaxNumberException e) {  
	        assertTrue(true);  
	    }  
	}  
}
