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
	
	// Tests invalid max number: 1.
    public void testMaxNumberOne() throws Exception {
        try {  
        	primeGenerator.generatePrimeTo(1);  
            fail("Should have throw InvalidMaxNumberException");  
        } catch (InvalidMaxNumberException e) {  
            assertTrue(true);  
        }  
    }  

    // Tests invalid max number: 0.
    public void testMaxNumberZero() throws Exception {  
        try {  
        	primeGenerator.generatePrimeTo(0);  
            fail("Should have throw InvalidMaxNumberException");  
        } catch (InvalidMaxNumberException e) {  
            assertTrue(true);  
        }  
    }  
    
	// Verifies if the returned prime string matches the expected string.
	private void verifyGeneratedPrime(String expectedList, int max)
			throws Exception {
		assertEquals(expectedList, primeGenerator.generatePrimeTo(max));
	}
}
