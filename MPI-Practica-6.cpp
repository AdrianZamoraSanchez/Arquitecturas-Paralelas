#include <mpi.h>
#include <iostream>

int main(int argc, char* argv[])
{
    // Declaración de las variables del programa
    int mirango, dato = 0, resultado = 0;

    // Inicialización de MPI
    MPI_Init(&argc, &argv);
    // Almacena el rango de cada proceso en la variable mirango
    MPI_Comm_rank(MPI_COMM_WORLD, &mirango);   

    // Crea dos variabes que controlan la comunicación entre procesos
    MPI_Request request_send, request_recv;

    if (mirango == 0) {
        // Bucle que mantiene funcionando el proceso 0, que pide datos y muestra los resutados
        while (true) {
            std::cout << "Proceso " << mirango << ": Introduce un numero para calcular su factorial: ";
            std::cin >> dato;

            // Envía el dato al proceso 1 para su cálculo
            MPI_Isend(&dato, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request_send);
            std::cout << "Proceso " << mirango << ": numero(" << dato << ") enviado!\n";

            // Comprueba la condición de salida
            if (dato == 0) {
                break; // Salir del bucle si el usuario ingresa 0
            }

            std::cout << "Proceso " << mirango << ": recibiendo resultados...\n";

            // Recibe el resultado del proceso 1
            MPI_Irecv(&resultado, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &request_recv);
            // Espera a recibir el resultado
            MPI_Wait(&request_recv, MPI_STATUS_IGNORE); 

            // Muestra el resultado
            std::cout << "Proceso " << mirango << ": el resultado de: " << dato << "! = " << resultado << "\n";
        }
    }
    if (mirango == 1) {
        // Bucle que mantiene funcionando el proceso 1, que recibe el dato, calcula el factorial y devuelve el resultado
        while (true) {
            // Se espera a recibir el numero del que queremos calcular su factorial
            MPI_Irecv(&dato, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request_recv);
            // Espera a recibir el numero
            MPI_Wait(&request_recv, MPI_STATUS_IGNORE); 

            // Comprueba la condición de salida
            if (dato == 0) {
                break; // Salir del bucle si se recibe 0
            }

            // Calcula el factorial
            int factorial = 1;
            for (int i = 1; i <= dato; ++i) {
                factorial *= i;
            }

            // Envía el resultado al proceso 0
            MPI_Isend(&factorial, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &request_send);
        }
    }

    // Finaliza el programa
    MPI_Finalize();
    return 0;
}
