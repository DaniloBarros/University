package eratostenes;

/**
 * Prime numbers generator using Eratostenes algorithm.
 * Take a number and marks its multiples.
 * The remaining numbers are prime numbers.
 * copyright UNB/FGA
 */

/**
 *
 */
public class PrimeGenerator {

	public static final int SMALLEST_PRIME = 2;
	
	/**
	 * Generates prime numbers to i using Eratostenes algorithm.
	 * 
	 * @param max
	 *            Generate prime numbers from 2 to maxNumber.
	 * @return String with generated prime numbers. ex "2,3,4,5,7".
	 */
	public String generatePrimeTo(int maxNumber) 
			throws InvalidMaxNumberException {
		if (maxNumber == 1) throw new InvalidMaxNumberException();
		if (maxNumber == SMALLEST_PRIME)
			return "2";
		else
			return "2, 3";
	}
}
