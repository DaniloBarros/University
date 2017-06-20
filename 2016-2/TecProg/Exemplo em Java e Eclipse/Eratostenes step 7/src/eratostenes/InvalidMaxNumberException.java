package eratostenes;

public class InvalidMaxNumberException extends Exception {
	
	/**
	 * Compiler generated serialVersionUID for serialization
	 */
	private static final long serialVersionUID = 6126503723843382381L;

	public InvalidMaxNumberException() {
		super("Max number must be greater than 2");
	}
}
