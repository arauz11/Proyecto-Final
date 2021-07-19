#include "sqlite3.h"
#include <stdio.h>

int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("clinica1.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "DROP TABLE IF EXISTS pacientes1;" 
                "CREATE TABLE pacientes1(Numero_de_record_clínico INT, ID INT,Nombre_del_paciente TEXT, Apellido_del_paciente TEXT, Edad    INT, Fecha_de_nacimiento varchar);" 
                
                "INSERT INTO pacientes1 VALUES(1, '4 7531 9510', 'Lucia', 'Guardia Cerezo', '38', '16/09/1983');" 
                
                "INSERT INTO pacientes1 VALUES(2, '3 1582 9632', 'Víctor', 'García Montoya', '25', '25/06/1996');" 
                
                "INSERT INTO pacientes1 VALUES(3, '2 8932 2031', 'José Antonio', 'Pérez Gómez', '32', '20/08/1989');" 
                
                "INSERT INTO pacientes1 VALUES(4, '1 5820 7913', 'Juan', 'Pérez Cayuela', '16', '12/05/2005');" 
                
                "INSERT INTO pacientes1 VALUES(5, '1 9632 7412', 'Ana María', 'Velasco Sánchez', '52', '23/05/1969');"
                
                "INSERT INTO pacientes1 VALUES(6, '5 8956 3215', 'Isabel', 'García Martínez', '29', '08/04/1992');"
                
                "INSERT INTO pacientes1 VALUES(7, '6 8914 8523', 'Carlos', 'Rojas Rojas', '30', '17/10/1991');"
                
                "INSERT INTO pacientes1 VALUES(8, '1 1325 0265', 'Miguel', 'Calderón Suarez', '48', '10/02/1973');";


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

