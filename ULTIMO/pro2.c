#include "sqlite3.h"
#include <stdio.h>

int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("clinica2.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "DROP TABLE IF EXISTS pacientes2;" 
    
                "CREATE TABLE pacientes2(Nombre_y_apellido_del_doctor TEXT, Fecha_de_la_cita varchar, Diagnostico TEXT,Departamento TEXT, Tratamiento_medico_recomendado TEXT);" 
                
                "INSERT INTO pacientes2 VALUES('Alejandro Martí Giménez', '02/08/2021', 'Acné', 'Dermatología', 'Peróxido de benzoílo');" 
                
                "INSERT INTO pacientes2 VALUES('Francisco Palacios Ortega', '03/08/2021', 'Anemia', 'Hematología y Hemoterapia', 'Vitamina B12 o Acido fólico');" 
                
                "INSERT INTO pacientes2 VALUES('María Rosa Sánchez Navarro', '04/08/2021', 'Cistitis', 'Urología', 'Antibióticos');" 
                
                "INSERT INTO pacientes2 VALUES('Manuel Samaniego Muñoz', '05/08/2021', 'Alergia', 'Alergología y Clínica Inmunología', 'Antihistamínicos');" 
                
                "INSERT INTO pacientes2 VALUES('Ana María García Arauz', '06/08/2021', 'Edema', 'Nefrología', 'Reposo en cama con elevación de extremidades');"
                
                "INSERT INTO pacientes2 VALUES('Isabel Aguilar Sosa', '09/08/2021', 'Gripe', 'Medicina Interna', 'Se aconseja un reposo relativo y una buena hidratación');"
                
                "INSERT INTO pacientes2 VALUES('Carlos Duran Castillo', '10/08/2021', 'Hepatitis B', 'Hepatología', 'La hepatitis B crónica se trata con medicamentos antivirales, como interferón alfa, lamivudina, adefovir-dipivoxil, entecavir o combinaciones de los mismos');"
                
                "INSERT INTO pacientes2 VALUES('Miguel Salazar Mena', '11/08/2021', 'Insuficiencia cardiaca', 'Cardiología', 'En un primer momento se aplican medidas médico-farmacológicas');";


    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}

