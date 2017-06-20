####Style Sheet 
###Danilo Barros Mendes
---
- [x] Names
- [x] Constants
- [x] Identation
- [x] Brackets
- [x] Comments
- [x] Math Operators
---
##Names

Names should use the CamelCase writing format. [CamelCase reference](https://en.wikipedia.org/wiki/CamelCase)
This includes functions names, variables, methods, class name.
On the exeption of class names and constant names, all other should start with a lower case letter.

**Example**
Bad code:
```java
private String license_Plate;
private String license_plate;
private String Licenseplate;
private String licenseplate;
```
Good code:
```java
private String licensePlate;
public class RegisterData
public void registerOwners()
```

##Constants

All constants should be named in all caps, separated by underscore.

**Example**
Bad code:
```java
public const int constant = 2;
public const int constant_int = 2;
public const int constantCons = 2;
```

Good code:
```java
public const int CONSTANT = 2;
public const int CONSTANT_INT = 2;
```

##Identation

Identation should use a tab size of 4 spaces, throughout the code, except in the beginning of a class, then it should be aligned with the left margin.


**Example**
Bad code:
```java
public class MainClass{

  public static void main(String[] args){

	RegisterData ownerData = new RegisterData();
		
	ownerData.registerOwners();
	}
}
```
Good code:
```java
public class MainClass{

	public static void main(String[] args){

		RegisterData ownerData = new RegisterData();
		
		ownerData.registerOwners();
	}
}
```

##Brackets

Brackets should open in the same line as it scope and closes in the next line after the scope should end.
Also is a requirement that it exists a new line separating the open bracket and the next line of code.
There should not exist a space before a open bracket.

**Example**
Bad code:
```java
for(int j=0; j< ownersList.get(i).getListVehicles().size(); j++)
{
	System.out.println(ownersList.get(i).getListVehicles().get(j));
}

for(int j=0; j< ownersList.get(i).getListVehicles().size(); j++){System.out.println(ownersList.get(i).getListVehicles().get(j));}

for(int j=0; j< ownersList.get(i).getListVehicles().size(); j++){
	System.out.println(ownersList.get(i).getListVehicles().get(j));
}
```

Good code:
```java
for(int j=0; j< ownersList.get(i).getListVehicles().size(); j++){

	System.out.println(ownersList.get(i).getListVehicles().get(j));
}
```

##Comments

Comments that exceeds one line of comment should be done as a block of comments wrapped in /** */, with every new line preceeded with a *.
Comments that are in a single line should only be done as a double slash comment.
After double slash comments there should be a space separating the first letter and the double slash.
Before every method should be a block of comment stating the parameters and explaning them coherently, if it has any, and return type, if it has any.

**Example**
Bad code:
```java
// Sets the model name of the vehicle
// @param model - Name of the model

/* Empty constructor required. */

/*
 * Sets the model name of the vehicle
 * @param model - Name of the model
 */
```

Good code:
```java
// Empty constructor required.

/**
 * Sets the model name of the vehicle
 * @param model - Name of the model
 */
 ```

##Math Operators

All maths operators and the assgment operators should be preceeded and followed by a blank space.
Exception to the ! operator, that should not be preeceded by a blank space.

**Example**
Bad code:
```java
int hasCar=0;

String result = resultBrand+resultModel+resultYear+resultLicense+resultColor;

if(a==b)

if(booleanVar !)
```

Good code:
```java
int hasCar = 0;

String result = resultBrand + resultModel + resultYear + resultLicense + resultColor;

if(a == b)

if(booleanVar!)
```