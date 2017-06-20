/**
 * Test the PrimeNumbersGenerator class using JUnit test cases
 * 
 */
package testcases;

import eratostenes.PrimeNumbersGenerator;
import junit.framework.TestCase;

/**
 * Unit test cases to test the PrimeNumbersGenerator class.
 * copyright UnB FGA
 */
public class PrimeNumbersGeneratorTest extends TestCase {
	// Test the first prime number
	public void testPrimeNumbersToTwo() throws Exception {  
		PrimeNumbersGenerator primeNumbersGenerator = new PrimeNumbersGenerator();  
        assertEquals("2", primeNumbersGenerator.generatePrimeNumbersTo(2));  
    }  
}
