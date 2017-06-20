package testcases;

/**
 * Test the PrimeNumbersGenerator class using JUnit test cases
 * 
 */

import eratostenes.PrimeNumbersGenerator;
import junit.framework.TestCase;

/**
 * Unit test cases to test the PrimeNumbersGenerator class.
 * 
 */
public class PrimeNumbersGeneratorTest extends TestCase {

	// Test the first prime number
	public void testPrimeNumbersToTwo() throws Exception {
		verifyGeneratedPrimeNumbers("2", 2);
	}

	// Test two prime numbers
	public void testPrimeNumbersToThree() throws Exception {
		verifyGeneratedPrimeNumbers("2, 3", 3);
	}

	private void verifyGeneratedPrimeNumbers(String expectedList, int max)
			throws Exception {
		PrimeNumbersGenerator primeNumbersGenerator = new PrimeNumbersGenerator();
		assertEquals(expectedList, primeNumbersGenerator.generatePrimeNumbersTo(max));
	}
}
