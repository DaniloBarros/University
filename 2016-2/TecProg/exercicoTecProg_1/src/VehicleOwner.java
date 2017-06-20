import java.util.ArrayList;
import java.util.List;

/**
 * File: VehicleOwner.java
 * Purpose: Maintain Vehicle owner's data
 */

public class VehicleOwner{

	private String name = "";
	private int cnh = 0;
	private String address = "";
	private List<Vehicle> listVehicles = new ArrayList<Vehicle>();
	
	public VehicleOwner(){
		//Empty Constructor required
	}

	/**
	 * Constructs Vehicle's owner with the given information
	 * @param name - Name of the owner
	 * @param cnh - Identification of the owner, ensure the permission to drive
	 * @param address - Address of the owner's residence
	 * @param listVehicles - Identify all the vehicles of this owner
	 */
	protected VehicleOwner(String name, int cnh, String address, List<Vehicle> listVehicles){
		setName( name );
		setCnh( cnh );
		setAddress( address );
		setVehicles( listVehicles );
	}

	/**
	 * Sets the name of the user
	 * @param name- Name of the owner
	 */
	public void setName(String name){
		this.name = name;
	}

	/**
	 * Sets the cnh of the user
	 * @param cnh- Identification of the owner, ensure the permission to drive
	 */
	public void setCnh(int cnh){
		this.cnh = cnh;
	}

	/**
	 * Sets the address of the user
	 * @param address - Address of the owner's residence
	 */
	public void setAddress(String address){
		this.address = address;
	}

	/**
	 * Sets the list of vehicles that an user has
	 * @param listVehicles - Identify all the vehicles of this owner
	 */
	private void setVehicles(List<Vehicle> listVehicles){
		this.listVehicles = listVehicles;
	}

	/**
	 * Gets the name of the user
	 * @return String - User name
	 */
	public String getName(){
		return name;
	}

	/**
	 * Gets the cnh of the user
	 * @return int - User cnh
	 */
	public int getCnh(){
		return cnh;
	}

	/**
	 * Gets the address of the user
	 * @return String - Address of the User
	 */
	public String getAddress(){
		return address;
	}

	/**
	 * Gets the list of vehicles of the user
	 * @return ArrayList - List of vehicles
	 */
	public List<Vehicle> getListVehicles(){
		return listVehicles;
	}

	/**
	 * Return the main information about the vehicle owner
	 * @return String - name, cnh and address information separated by new line
	 */
	@Override
	public String toString(){
		String resultName = "\n" + "Nome: " + name;
		String resultCnh = "\n" + "CNH: " + cnh;
		String resultAddress = "\n" + "Endereço: " + address; 
		String result = resultName + resultCnh + resultAddress + "\n";

		return result;
	}

}
