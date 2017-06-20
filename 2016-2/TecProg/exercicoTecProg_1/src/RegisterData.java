import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * File: RegisterData.java
 * Purpose: Registers data of the vehicle 
 */

public class RegisterData{

	Scanner scanner = new Scanner (System.in);

	VehicleOwner owner;
	List<VehicleOwner> ownersList = new ArrayList<VehicleOwner>();

	Vehicle car;

	public void registerOwners(){
		int option = 0;

		do{

			System.out.println( "## Escolha uma das opções abaixo ##" );
			System.out.println( "Opção 1 - Cadastra Propietários de Automóveis" );
			System.out.println( "Opção 2 - Lista proprietários cadastrados" );
			System.out.println( "Opção 0 - Sair do programa" );
			System.out.println( "_______________________" );
			System.out.print( "Digite aqui sua opção: " );
			String userEntrance = scanner.nextLine();
			option = Integer.parseInt(userEntrance);

			switch( option ){

				case 1:{

					owner = new VehicleOwner();
					int hasCar = 0;

					System.out.print( "Digite o nome do proprietário do veículo: " );
					owner.setName( scanner.nextLine() );

					System.out.print( "Digite a sua CNH: " );
					owner.setCnh(Integer.parseInt( scanner.nextLine()) );

					System.out.print( "Digite o seu endereço: " );
					owner.setAddress( scanner.nextLine() );

					ownersList.add( owner );

					do{

						registerVehicle( ownersList.size()-1 );

						System.out.print( "A pessoa cadastrada possui veículo em seu nome?" + 
								"\n" + "Responda 1 para sim e 2 para não." );
						hasCar = Integer.parseInt( scanner.nextLine() );					

					}while( hasCar );

					System.out.println();

				}break;

				case 2:{

					if( ownersList.isEmpty() ){

						System.out.println( "Não existem proprietários cadastrados, pressione uma tecla para continuar!" );
						scanner.nextLine();

					}else{

						System.out.println("");

						for(int i=0; i< ownersList.size(); i++){
							
							System.out.println( ownersList.get(i) );

							for(int j=0; j< ownersList.get(i).getListVehicles().size(); j++){

								System.out.println( ownersList.get(i).getListVehicles().get(j) );
							}
						}

						System.out.println( "Pressione um tecla para continuar." );
						scanner.nextLine();
					}	
				
				}break;
				default:
					System.out.println("Opcao incorreta!\n");
			}

		}while(option != 0);		

		scanner.close();
	}


	private void registerVehicle(int idOwner) {

		car = new Vehicle();

		System.out.print( "Digite a marca do veículo: " );
		car.setBrand( scanner.nextLine() );

		System.out.print( "Digite o modelo do veículo: " );
		car.setModel( scanner.nextLine() );

		System.out.print( "Digite o ano do veículo: " );
		car.setYear( Integer.parseInt( scanner.nextLine() ) );

		System.out.print( "Digite a placa do veículo: " );
		car.setlicensePlate( scanner.nextLine() );

		System.out.print( "Digite a cor do veículo: " );
		car.setColor( scanner.nextLine() );

		System.out.println();

		ownersList.get( idOwner ).getListVehicles().add( car );
	}

	private boolean onlyCharacters(String name){
		String regx = "^[\\p{L} .'-]+$";
		Pattern pattern = Pattern.compile(regx, Pattern.CASE_INSENSITIVE);
		boolean hasSpecialChar = pattern.matcher(name).find();

		return hasSpecialChar;
	}

	private boolean 

}