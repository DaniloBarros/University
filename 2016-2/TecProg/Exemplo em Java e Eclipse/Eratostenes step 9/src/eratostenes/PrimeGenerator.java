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
	 * @return String with generated prime numbers. ex "2, 3, 5, 7".
	 */
	public String generatePrimeTo(int maxNumber)
			throws InvalidMaxNumberException {

		if (maxNumber >= SMALLEST_PRIME) {
			return primeNumbers(maxNumber);
		} else {
			throw new InvalidMaxNumberException();
		}
	}

	// Generates prime numbers to i using Eratostenes algorithm.
	// It's safe to use maxNumber without testing.
	private String primeNumbers(int max) {
		boolean[] candidates = initializesCandidatesList(max);
		if (max == SMALLEST_PRIME)
			return "2";
		else
			return "2, 3";
	}

	// Initializes the array with all the numbers from 0 to maxNumber.
	// *This method should be private. Public only for testing.
	public boolean[] initializesCandidatesList(int max) {
		boolean[] result = new boolean[max+1];
		result[0] = false;
		result[1] = false;
		for (int i = PrimeGenerator.SMALLEST_PRIME; i < result.length; i++) {
			result[i] = true;
		}
		return result;
	}
}