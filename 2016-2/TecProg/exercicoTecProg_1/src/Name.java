public class Name{

	private String name;

	public Name(){

	}

	public Name(String name){
		this.name = setName(name);
	}

	public String getName(){
		return this.name;
	}

	public void setName(String name){
		boolean validName = this.validateName(name);
		
		if(validName){
			this.name = name;
		}else{
			this.name = "";
		}
	}


}