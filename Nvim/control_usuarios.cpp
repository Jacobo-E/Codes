#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define direcArchW "c:/borrame/Usuarios_Estructura_Datos_MAC.txt"
#define direcArchWBORRAME "c:/borrame/Usuarios_Estructura_Datos_MAC_AUXILIAR.txt"
#define direcArchLinux "Usuarios_Estructura_Datos_MAC.txt"
#define direcArchLinuxBORRAME "Usuarios_Estructura_Datos_MAC_AUXILIAR.txt"

enum sexo{
    hombre=1,
    mujer
};

typedef struct usuarios{

    private:
        int idUser;
        char login[15];
        char password[20];
        char nombre[25];
        char apellidoP[25];
        char apellidoS[25];
        char email[35];
        char telefono[13];
        sexo sexU;

    public:
        void leeUser(){
            printf("\t>idUser: ");
            scanf("%d", &idUser);
            printf("Login: ");
            cin >> login;
            printf("Pasword: ");
            cin >> password;
            printf("Nombre: ");
            cin >> nombre;
            printf("Primer apellido: ");
            cin >> apellidoP;
            printf("Segundo apellido: ");
            cin >> apellidoS;
            printf("E-mail: ");
            cin >> email;
            printf("telefono: ");
            cin >> telefono;
        }

        void guardaUser(){
            FILE *archi;
            archi = fopen(direcArchLinux, "a");
            if(archi==NULL){
                printf("\nError en la apertura de archivo.\n");
                return;
            }

            fprintf(archi, "%d\n", idUser);
            fputs(login, archi);
            fputs(password, archi);
            fputs(nombre, archi);
            fputs(apellidoP, archi);
            fputs(apellidoS, archi);
            fputs(email, archi);
            fputs(telefono, archi);

            fclose(archi);
            printf("\nEl registro ha sido almacenado con éxito.\n");
        }

        void imprimirUser(){
            printf("\n\t>id Usuario: %d", idUser);
            printf("\nLogin: %s", login);
            printf("Password: %s", password);
            printf("Nombre: %s", nombre);
            printf("Primer Apellido: %s", apellidoP);
            printf("Segundo Apellido: %s", apellidoS);
            printf("Email: %s", email);
            printf("Telefono: %s", telefono);
        }

        void busquedaUsuario(int id_buscado){
            FILE *archi;
            usuarios aux;
            archi = fopen(direcArchLinux, "r");

            if(archi==NULL){
                printf("\nError en la apertura de archivo.\n");
                return;
            }

            while(!feof(archi)){
                fscanf(archi, "%d\n", &aux.idUser);
                fflush(stdin);
                fgets(aux.login, 15, archi);
                fgets(aux.password, 20, archi);
                fgets(aux.nombre, 25, archi);
                fgets(aux.apellidoP, 25, archi);
                fgets(aux.apellidoS, 25, archi);
                fgets(aux.email, 25, archi);
                fgets(aux.telefono, 15, archi);

                if(aux.idUser == id_buscado){
                    printf("\nEl registro encontrado es: \n");
                    aux.imprimirUser();
                    return;
                }
            }

            fclose(archi);
            printf("\nRegistro no encontrado.");

        }

        static void eliminaRegistro(int id_buscado){
            FILE *archi, *borrame;
            usuarios aux;
            archi = fopen(direcArchLinux, "r");
            borrame = fopen(direcArchLinuxBORRAME, "w");

            if(archi==NULL || borrame==NULL){
                printf("\nError en la apertura de los archivos.\n");
                return;
            }

            while(!feof(archi)){
                fscanf(archi, "%d\n", &aux.idUser);
                fflush(stdin);
                fgets(aux.login, 15, archi);
                fgets(aux.password, 20, archi);
                fgets(aux.nombre, 25, archi);
                fgets(aux.apellidoP, 25, archi);
                fgets(aux.apellidoS, 25, archi);
                fgets(aux.email, 25, archi);
                fgets(aux.telefono, 15, archi);

                if(aux.idUser == id_buscado){
                    printf("\nRegistro eliminado es: \n");
                    aux.imprimirUser();
                }else{
                    fprintf(borrame, "%d\n", aux.idUser);
                    fputs(aux.login, borrame);
                    fputs(aux.password, borrame);
                    fputs(aux.nombre,borrame);
                    fputs(aux.apellidoP, borrame);
                    fputs(aux.apellidoS, borrame);
                    fputs(aux.email, borrame);
                    fputs(aux.telefono, borrame);
                }
            }

            fclose(borrame);
            fclose(archi);
            remove(direcArchLinux);
            rename(direcArchLinuxBORRAME, direcArchLinux);

        }

        void listarUsuarios(){
            FILE *archi;
            usuarios aux;
            archi = fopen(direcArchLinux, "r");

            if(archi==NULL){
                printf("\nError en la apertura de archivo.\n");
                return;
            }

            while(!feof(archi)){
                fscanf(archi, "%d\n", &aux.idUser);
                fflush(stdin);
                fgets(aux.login, 15, archi);
                fgets(aux.password, 20, archi);
                fgets(aux.nombre, 25, archi);
                fgets(aux.apellidoP, 25, archi);
                fgets(aux.apellidoS, 25, archi);
                fgets(aux.email, 25, archi);
                fgets(aux.telefono, 15, archi);

                aux.imprimirUser();
            }

            fclose(archi);
        }

        void modificaRegistro(int id_buscado){
            FILE *archi, *borrame;
            usuarios aux;
            int centinela=0;
            archi = fopen(direcArchLinux, "r");
            borrame = fopen(direcArchLinuxBORRAME, "w");

            if(archi==NULL || borrame==NULL){
                printf("\nError en la apertura de los archivos.\n");
                return;
            }

            while(!feof(archi)){
                fscanf(archi, "%d\n", &aux.idUser);
                fflush(stdin);
                fgets(aux.login, 15, archi);
                fgets(aux.password, 20, archi);
                fgets(aux.nombre, 25, archi);
                fgets(aux.apellidoP, 25, archi);
                fgets(aux.apellidoS, 25, archi);
                fgets(aux.email, 25, archi);
                fgets(aux.telefono, 15, archi);

                if(aux.idUser == id_buscado){
                    printf("\nRegistro encontrado.\n");
                    aux.imprimirUser();
                    printf("\n\tAcción a realizar.\n[1] Modificar Login.\n[2] Modificar Password.\n[3] Modificar Nombre.");
                    printf("\n[4] Modificar Primer Apellido.\n[5] Modificar Segundo Apellido.\n[6] Modificar E-mail.\n[7] Modificar Telefono.\n");
                    int opcion=0;
                    scanf("%d", &opcion);
                    switch(opcion){
                        case 1:
                            printf("\nLogin: ");
                            cin >> aux.login;
                            break;
                        case 2:
                            printf("\nPassword: ");
                            cin >> aux.password;
                            break;
                        case 3:
                            printf("\nNombre: ");
                            cin >> aux.nombre;
                            break;
                        case 4:
                            printf("\nPrimer Apellido: ");
                            cin >> aux.apellidoP;
                            break;
                        case 5:
                            printf("\nSegundo Apellido: ");
                            cin >> aux.apellidoS;
                            break;
                        case 6:
                            printf("\nE-mail: ");
                            cin >> aux.email;
                            break;
                        case 7:
                            printf("\nTelefono: ");
                            cin >> aux.telefono;
                            break;
                    }
                    centinela=1;
                    fprintf(borrame, "%d\n", aux.idUser);
                    fputs(aux.login, borrame);
                    fputs(aux.password, borrame);
                    fputs(aux.nombre,borrame);
                    fputs(aux.apellidoP, borrame);
                    fputs(aux.apellidoS, borrame);
                    fputs(aux.email, borrame);
                    fputs(aux.telefono, borrame);

                    printf("\nRegistro con los cambios:\n");
                    aux.imprimirUser();
                }else{
                    fprintf(borrame, "%d\n", aux.idUser);
                    fputs(aux.login, borrame);
                    fputs(aux.password, borrame);
                    fputs(aux.nombre,borrame);
                    fputs(aux.apellidoP, borrame);
                    fputs(aux.apellidoS, borrame);
                    fputs(aux.email, borrame);
                    fputs(aux.telefono, borrame);
                }

                if(centinela){
                    remove(direcArchLinux);
                    rename(direcArchLinuxBORRAME, direcArchLinux);	
                    printf("\n El registro fue modificado con exito:\n");
                }else{
                    printf("\nEl usuario no existe.");
                    remove(direcArchLinuxBORRAME);
                }
            }

        }

        int acceso(){
            FILE *archi;
            usuarios aux;
            char admon[15], contra[20];
            int intentos=0, acceso=0;
            archi = fopen(direcArchLinux, "r");

            printf("\nIngrese un usuario administrador: ");
            cin >> admon;

            if(archi==NULL){
                return printf("\nError en la apertura de archivo.\n");
            }

            while(!(strcmp(admon, "root") || strcmp(admon, "mac1351"))){
                printf("\nUsuario ingresado no registrado como administrador.\n");
            }

            while(!feof(archi)){
                fscanf(archi, "%d\n", &aux.idUser);
                fflush(stdin);
                fgets(aux.login, 15, archi);
                fgets(aux.password, 20, archi);
                fgets(aux.nombre, 25, archi);
                fgets(aux.apellidoP, 25, archi);
                fgets(aux.apellidoS, 25, archi);
                fgets(aux.email, 25, archi);
                fgets(aux.telefono, 15, archi);

                if(strcmp(aux.login, admon)){
                    printf("\nIngrese la contraseña: ");
                    do{
                        if(intentos < 6){
                            cin >> contra;
                            if(intentos>=1){
                                printf("\nContraseña incorrecta. Intente de nuevo.\n");
                            }
                            intentos++;
                        }else{
                            printf("\nLimite de intentos excedido.\n");
                            acceso=0;
                        }
                    }while(!(strcmp(aux.password, contra)));
                    }
                }

            if(intentos < 6){
                acceso=1;
            }else{
                acceso=0;
            }

                fclose(archi);
                return acceso;
            }

}user;

int main(){

    char respuesta={};
    int opcion=0, x=0, pase=0, terminar=0;

    printf("\nBienvenido al sistema de registro de usuarios.\n");

    do{
        printf("\nIntroduzca la acción que desea realizar:");
        printf("\n[1] Guardar registro.\n[2] Buscar usuario.\n[3] Borrar un usuario.");
        printf("\n[4] Listar usuarios almacenados.\n[5] Modificar un registro.\n");
        scanf("%d", &opcion);
        user main;

        do{
            pase = main.acceso();
        }while(pase==0);

        switch(opcion){
            case 1:
                main.leeUser();
                main.guardaUser();
                break;
            case 2:
                printf("\nIntroduzca el ID del usuario a buscar: ");
                scanf("%d", &x);
                main.busquedaUsuario(x);
                break;
            case 3:
                printf("\nIntroduzca el ID del usuario a borrar: ");
                scanf("%d", &x);
                main.eliminaRegistro(x);
            case 4:
                main.listarUsuarios();
                break;
            case 5:
                printf("\nIntroduzca el ID del usuario a modificar: ");
                scanf("%d", &x);
                main.modificaRegistro(x);
                break;
            default:
                printf("\nOpción inválida. Intente nuevamente.\n");
                break;
        }

        printf("\n¿Desea seguir ejecutando el sistema? [s/S -> si | n/N -> no]: ");
        fflush(stdin);
        scanf("%c", &respuesta);

    }while(respuesta == 's' || respuesta == 'S');

return 0;}
