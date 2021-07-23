#include<stdio.h>
#include<string.h>


// Esto es para imprimir a todos los pacientes del archivo.
void printList()
{
	FILE *file = fopen("clinica.txt", "r");
	if(file == NULL)
	{
		printf("No se puede abrir clinica.txt\n");
		return;
	}

	char line[1024];
	fgets(line, 1024, file); // Skip header


	// Leer hasta el final del archivo.
	while(fgets(line, 1024, file))
	{

		// Separar la información por |, usar strtok

		char *token = strtok(line, "|");	
		printf(" Número de record clínico: %s\n", token);
		
		token = strtok(NULL, "|");
		printf("ID: %s\n", token);

		token = strtok(NULL, "|");
		printf("Nombre del Paciente: %s\n", token);

		token = strtok(NULL, "|");
		printf("Apellido del Paciente: %s\n", token);

		token = strtok(NULL, "|");
		printf("Edad: %s\n", token);

		token = strtok(NULL, "|");
		printf("Fecha de Nacimiento: %s\n", token);

		token = strtok(NULL, "|");
		printf("Nombre del doctor: %s\n", token);

		token = strtok(NULL, "|");
		printf("Fecha de la cita: %s\n", token);

		token = strtok(NULL, "|");
		printf("Diagnóstico: %s\n", token);

		token = strtok(NULL, "|");
		printf("Departmento: %s\n", token);

		token = strtok(NULL, "|");
		printf("Tratamiento médico recomendado: %s\n\n", token);
	}

	fclose(file);
}



// Se utiliza para buscar un paciente en el archivo.
void searchPatient()
{
	FILE *file = fopen("clinica.txt", "r");
	if(file == NULL)
	{
		printf("No se puede abrir clinica.txt\n");
		return;
	}

	//Recibe la información del usuario.
	printf("Ingrese el número de record clínico, nombre o ID del paciente");
	char data[100];
	gets(data);



	char line[1024];
	fgets(line, 1024, file); // Skip header


	// Leer el archivo hsta el final.
	while(fgets(line, 1024, file))
	{   

		// Dividir el record clínico, el nombre y el ID para hacer coincidir y verificar.
		char* record = strtok(line, "|");
		char* id = strtok(NULL, "|");
		char* name = strtok(NULL, "|");


		/* Si alguno de los ID, o nombres, o registro clinico coincide con los datos de entrada del usuario, imprima este 			paciente.*/

		if( strcmp(record, data) ==0 || strcmp(id, data) ==0  || strcmp(name, data)==0)

		{
		printf("Número de record clínico: %s\n", record);
		printf("ID: %s\n", id);
		printf("Nombre del Paciente: %s\n", name);
		
		char *token = strtok(NULL, "|");
		printf("Nombre del Paciente: %s\n", token);

		token = strtok(NULL, "|");
		printf("Apellido del Paciente: %s\n", token);

		token = strtok(NULL, "|");
		printf("Edad: %s\n", token);

		token = strtok(NULL, "|");
		printf("Fecha de Nacimiento: %s\n", token);

		token = strtok(NULL, "|");
		printf("Nombre del doctor: %s\n", token);

		token = strtok(NULL, "|");
		printf("Fecha de la cita: %s\n", token);

		token = strtok(NULL, "|");
		printf("Diagnóstico: %s\n", token);

		token = strtok(NULL, "|");
		printf("Departmento: %s\n", token);

		token = strtok(NULL, "|");
		printf("Tratamiento médico recomendado: %s\n\n", token);

		break;
		}
	}

	fclose(file);
}


// Esto agrega un nuevo paciente en el archivo.
void addPatient()
{
	// Abrir en append mode
	FILE *file = fopen("clinica.txt", "a");
	if(file == NULL)
	{
		printf("No se puede abrir clinica.txt\n");
		return;
	}

	// Toma la entrada y la escribe en el archivo
	char data[100];


	printf("Ingrese el Número de record clínico: ");
	gets(data);
	fputs(" \n", file);
	fputs(data, file); // Ingrese una nueva línea para el siguiente registro
	fputs("|", file);

	printf("Ingrese ID: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese Nombre del Paciente: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese Apellido del Paciente: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese la edad del Paciente: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese la fecha de nacimiento del Paciente: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese el Nombre del Doctor: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese la fecha de la cita: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese el Diagnóstico: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese el Departamento Médico: ");
	gets(data);
	fputs(data, file);
	fputs("|", file);

	printf("Ingrese el Tratamiento médico recomendado: ");
	gets(data);
	fputs(data, file);
	fputs("\n", file);

	printf("Paciente agregado\n");
	fclose(file);
}


// Esto puede eliminar a un paciente del archivo si se encuentra
void deletePatient()
{
	FILE *file = fopen("clinica.txt", "r");
	if(file == NULL)
	{
		printf("No se puede abrir clinica.txt\n");
		return;
	}

	// Escribir datos en otro archivo para luego cambiarle el nombre
	FILE *file2 = fopen("clinica2.txt", "w");


	// Obtener datos de usuario
	printf("Ingrese el número de record clínico, nombre o ID del paciente: ");
	char data[100];
	gets(data);
	//fputs(data, file);
	//fputs("\n", file);


  /* La lógica es leer la información de un archivo y escribir en otro archivo, excepto el paciente que se eliminará y luego eliminar el archivo original y cambiar el nombre del archivo nuevo al nombre del archivo anterior.*/
    
	char line[1024];
	char original_line[1024];

    
	fgets(line, 1024, file);
	fputs(line, file2); // Escribir el header

	while(fgets(line, 1024, file))
	{
		// Mantener la línea original, porque después de usar strtok puede modificarse
		strcpy(original_line, line);

		char* record = strtok(line, "|");
		char* id = strtok(NULL, "|");
		char* name = strtok(NULL, "|");

		if( strcmp(record, data) ==0 || strcmp(id, data) ==0  || strcmp(name, data)==0)
		{
		// No se escribe
		}
		else
		{
			fputs(original_line, file2);
		}
	}
    

	fclose(file);
	fclose(file2);

	remove("clinica.txt");
	rename("clinica2.txt", "clinica.txt");
}

// Menú para tomar la elección de los usuarios
int menu()
{
   // printf("\n1.Print list \n2.Search patient \n3. Add patient   \n4.Remove patient \n5.Exit:  ")
	printf("Presione 1 para ver la lista de pacientes\n");
	printf("Presione 2 para buscar un pacientes\n");
	printf("Presione 3 para agregar un paciente\n");
	printf("Presione 4 para eliminar un paciente\n");
	printf("Presione 5 para salir\n");
	printf("Ingrese su opción: ");
   
	int choice;
	scanf("%d", &choice);
	fflush(stdin); // Eliminar caracteres basura


	return choice;
}


int main()
{
	// Ejecutar loop
	while(1)
	{
		int input = menu();

		if(input == 1)
			printList();

		if(input == 2)
			searchPatient();

		if(input == 3)
			addPatient();

		if(input == 4)
			deletePatient();


		if(input == 5)
			break;
	}
}
