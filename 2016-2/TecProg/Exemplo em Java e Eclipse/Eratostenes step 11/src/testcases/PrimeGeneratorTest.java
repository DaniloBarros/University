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

	public void testPrimeNumbersToFour() throws Exception {
		verifyGeneratedPrime("2, 3", 4);
	}

	public void testPrimeNumbersToFive() throws Exception {
		verifyGeneratedPrime("2, 3, 5", 5);
	}

	public void testPrimeNumbersToTen() throws Exception {  
		verifyGeneratedPrime("2, 3, 5, 7", 10);  
	}  
	public void testPrimeNumbersToTwentyTwo() throws Exception {  
		verifyGeneratedPrime("2, 3, 5, 7, 11, 13, 17, 19", 22);  
	}
	
	// Tests invalid max number: 1.
	public void testMaxNumberOne() throws Exception {
		verifyInvalidMaxNumberRejected(1);
	}

	// Tests invalid max number: 0.
	public void testMaxNumberZero() {
		verifyInvalidMaxNumberRejected(0);
	}

	// Tests invalid max number: -1.
	public void testMaxNumberNegative() {
		verifyInvalidMaxNumberRejected(-1);
	}

	// Tests array initialization with numbers from 0 to 5.
	// 0 and 1 are not prime numbers and should be set to false.
	public void testCandidatesArrayInitialization() throws Exception {
		int max = 5;
		boolean[] candidates = primeGenerator
				.initializesPotentialPrimeList(max);
		assertFalse(candidates[0]);
		assertFalse(candidates[1]);
		for (int i = PrimeGenerator.SMALLEST_PRIME; i <= max; i++) {
			assertTrue(candidates[i]);
		}
	}

	// Verifies if the returned prime string equals the expected string.
	private void verifyGeneratedPrime(String expectedList, int max)
			throws Exception {
		assertEquals(expectedList, primeGenerator.generatePrimeTo(max));
	}

	// Verifies if the exception is throw for an invalid max number.
	private void verifyInvalidMaxNumberRejected(int maxNumber) {
		try {
			primeGenerator.generatePrimeTo(maxNumber);
			fail("Should have throw InvalidMaxNumberException");
		} catch (InvalidMaxNumberException e) {
			assertTrue(true);
		}
	}
}
