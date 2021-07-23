#include "sqlite3.h" // Importando la biblioteca necesaria para la ejecución de la base de datos.
#include <stdio.h>

int main(void) {
    
    sqlite3 *db; // Creando la instancia de sqlite3 como db.
    char *err_msg = 0; // Esto es necesario para almacenar el mensaje de error.
    
    int rc = sqlite3_open("clinica.db", &db); // Creando o abriendo la base de datos con el nombre "clinica.db", haciendo referencia a la variable db creada anteriormente.
    
    if (rc != SQLITE_OK) // rc almacenará el resultado o el estado de la base de datos, si no es SQLITE_OK, significa que hay un error al abrir la base de datos.
    
    {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db)); // Imprime el error.
        sqlite3_close(db); // Cierra la base de datos creada.
        
        return 1;
    }
    
    char *sql = "DROP TABLE IF EXISTS pacientes;"  // Elimine la tabla llamada pacientes si ya existe.
    
// Creando una nueva tabla llamada pacientes.
    
                "CREATE TABLE pacientes(Numero_de_record_clínico INT, ID INT,Nombre_del_paciente TEXT, Apellido_del_paciente TEXT, Edad    INT, Fecha_de_nacimiento varchar, Nombre_y_apellido_del_doctor TEXT, Fecha_de_la_cita varchar, Diagnostico TEXT,Departamento TEXT, Tratamiento_medico_recomendado TEXT);" 
                
// Insertar los valores en la tabla denominada pacientes.
 
                "INSERT INTO pacientes VALUES(1, '4 7531 9510', 'Lucia', 'Guardia Cerezo', '38', '16/09/1983', 'Alejandro Martí Giménez', '02/08/2021', 'Acné', 'Dermatología', 'Peróxido de benzoílo');" 
                
                "INSERT INTO pacientes VALUES(2, '3 1582 9632', 'Víctor', 'García Montoya', '25', '25/06/1996', 'Francisco Palacios Ortega', '03/08/2021', 'Anemia', 'Hematología y Hemoterapia', 'Vitamina B12 o Acido fólico');"
                
                "INSERT INTO pacientes VALUES(3, '2 8932 2031', 'José Antonio', 'Pérez Gómez', '32', '20/08/1989', 'María Rosa Sánchez Navarro', '04/08/2021', 'Cistitis', 'Urología', 'Antibióticos');" 
                
                "INSERT INTO pacientes VALUES(4, '1 5820 7913', 'Juan', 'Pérez Cayuela', '16', '12/05/2005', 'Manuel Samaniego Muñoz', '05/08/2021', 'Alergia', 'Alergología y Clínica Inmunología', 'Antihistamínicos');" 
                
                "INSERT INTO pacientes VALUES(5, '1 9632 7412', 'Ana María', 'Velasco Sánchez', '52', '23/05/1969', 'Ana María García Arauz', '06/08/2021', 'Edema', 'Nefrología', 'Reposo en cama con elevación de extremidades');"
                
                "INSERT INTO pacientes VALUES(6, '5 8956 3215', 'Isabel', 'García Martínez', '29', '08/04/1992', 'Isabel Aguilar Sosa', '09/08/2021', 'Gripe', 'Medicina Interna', 'Se aconseja un reposo relativo y una buena hidratación');"
                
                "INSERT INTO pacientes VALUES(7, '6 8914 8523', 'Carlos', 'Rojas Rojas', '30', '17/10/1991', 'Carlos Duran Castillo', '10/08/2021', 'Hepatitis B', 'Hepatología', 'La hepatitis B crónica se trata con medicamentos antivirales, como interferón alfa, lamivudina, adefovir-dipivoxil, entecavir o combinaciones de los mismos');"
                
                "INSERT INTO pacientes VALUES(8, '1 1325 0265', 'Miguel', 'Calderón Suarez', '48', '10/02/1973', 'Miguel Salazar Mena', '11/08/2021', 'Insuficiencia cardiaca', 'Cardiología', 'En un primer momento se aplican medidas médico-farmacológicas');";
                
              /*  "DROP TABLE IF EXISTS Pacien;"
                "CREATE TABLE Pacien(Numero_de_record_clínico INT,Fecha_de_la_cita varchar, Diagnostico TEXT,Departamento TEXT, Tratamiento_medico_recomendado TEXT);"
                
                "INSERT INTO Pacien VALUES(1, '02/08/2021', 'Acné', 'Dermatología', 'Peróxido de benzoílo');" 
                
                 "INSERT INTO Pacien VALUES(2, '03/08/2021', 'Anemia', 'Hematología y Hemoterapia', 'Vitamina B12 o Acido fólico');"
                
                "INSERT INTO Pacien VALUES(3, '04/08/2021', 'Cistitis', 'Urología', 'Antibióticos');" 
                
                "INSERT INTO Pacien VALUES(4, '05/08/2021', 'Alergia', 'Alergología y Clínica Inmunología', 'Antihistamínicos');" 
                
                "INSERT INTO Pacien VALUES(5, '06/08/2021', 'Edema', 'Nefrología', 'Reposo en cama con elevación de extremidades');"
                
                "INSERT INTO Pacien VALUES(6, '09/08/2021', 'Gripe', 'Medicina Interna', 'Se aconseja un reposo relativo y una buena hidratación');"
                
                "INSERT INTO Pacien VALUES(7, '10/08/2021', 'Hepatitis B', 'Hepatología', 'La hepatitis B crónica se trata con medicamentos antivirales, como interferón alfa, lamivudina, adefovir-dipivoxil, entecavir o combinaciones de los mismos');"
                
                "INSERT INTO Pacien VALUES(8, '11/08/2021', 'Insuficiencia cardiaca', 'Cardiología', 'En un primer momento se aplican medidas médico-farmacológicas');";*/
                
                


    rc = sqlite3_exec(db, sql, 0, 0, &err_msg); // Ejecutar la base de datos.
    
    if (rc != SQLITE_OK ) // rc almacenará el resultado o el estado de la base de datos, si no es SQLITE_OK, significa que hay un error en la ejecución de la base de datos.
    
    {
        
        fprintf(stderr, "SQL error: %s\n", err_msg); // Imprime el error.
        
        sqlite3_free(err_msg);        
        sqlite3_close(db); // Cierra la base de datos db abierta.
        
        return 1;
    } 
    
    sqlite3_close(db); // Cierra la base de datos.
    
    return 0;
}

