public class Vehicle{

/**
 * File: Vehicle.java
 * Purpose: Maintain Vehicle's data
 */

	private String brand;
	private String model;
	private int year;
	private String licensePlate;
	private String color;
	
	public Vehicle(){
		// Empty constructor required.
	}
	
	/**
	 * Constructs Vehicle's owner with the given information
	 * @param brand - Name of the brand
	 * @param model - Name of the model
	 * @param year - Number of the year
	 * @param licensePlate - Identification of the license plate
	 * @param color - Name of the color
	 */
	protected Vehicle(String brand, String model, int year, String licensePlate, String color){	
		setBrand( brand );
		setModel( model );
		setYear( year );
		setlicensePlate( licensePlate );
		setColor( color );
	}

	/**
	 * Sets the brand name of the vehicle
	 * @param brand - Name of the brand
	 */
	protected void setBrand(String brand){
		this.brand = brand;		
	}

	/**
	 * Sets the model name of the vehicle
	 * @param model - Name of the model
	 */
	protected void setModel(String model){
		this.model = model;
	}
	
	/**
	 * Sets the year number of the vehicle
	 * @param year - Number of the year
	 */
	protected void setYear(int year){
		this.year = year;
	}
	
	/**
	 * Sets the license plate identification of the vehicle
	 * @param licensePlate - Identification of the license plate
	 */
	protected void setlicensePlate(String licensePlate){
		this.licensePlate = licensePlate;
	}
	
	/**
	 * Sets the color name of the vehicle
	 * @param color - Name of the color
	 */
	protected void setColor (String color){
		this.color = color;
	}
	
	/**
	 * Gets the brand of the vehicle
	 * @return String - Vehicle's brand name
	 */
	protected String getBrand(){
		return brand;
	}
	
	/**
	 * Gets the model of the vehicle
	 * @return String - Vehicle's model name
	 */
	protected String getModel(){
		return model;
	}	

	/**
	 * Gets the year of the vehicle
	 * @return int - Vehicle's year number
	 */
	protected int getYear(){
		return year;
	}
	
	/**
	 * Gets the license plate of the vehicle
	 * @return String - Vehicle's license plate identification
	 */
	protected String getlicensePlate(){
		return licensePlate;
	}
	
	/**
	 * Gets the color of the vehicle
	 * @return String - Vehicle's color name
	 */
	protected String getColor(){
		return color;
	}
	
	/**
	 * Return the main information about the vehicle
	 * @return String - bramd, model, year, license and color information separated by new line
	 */
	@Override
	public String toString(){
		String resultBrand = "\n" + "Marca: " + brand + "";
		String resultModel = "\n" + "Modelo: " + model + "";
		String resultYear = "\n" + "Ano: " + year + "";
		String resultLicense =  "\n" + "Placa: " + licensePlate + "";
		String resultColor = "\n" + "Cor: " + color + "" + "\n";
		String result = resultBrand + resultModel + resultYear + resultLicense + resultColor;

		return result;
	}

}
