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

	// Test the first prime number.
	public void testPrimeToTwo() throws Exception {
		verifyGeneratedPrime("2", 2);
	}

	// Test two prime numbers.
	public void testPrimeNumbersToThree() throws Exception {
		verifyGeneratedPrime("2, 3", 3);
	}
	
	// 
    public void testMaxNumberOne() throws Exception {  
    	PrimeGenerator primeGenerator = new PrimeGenerator();
        try {  
        	primeGenerator.generatePrimeTo(1);  
            fail("Should have throw InvalidMaxNumberException");  
        } catch (InvalidMaxNumberException e) {  
            assertTrue(true);  
        }  
    }  

	// Verifies if the returned prime string matches the expected string.
	private void verifyGeneratedPrime(String expectedList, int max)
			throws Exception {
		PrimeGenerator primeGenerator = new PrimeGenerator();
		assertEquals(expectedList, primeGenerator.generatePrimeTo(max));
	}
}
