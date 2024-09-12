#include <iostream>
using namespace std;

class Empresa{
    private:
        char nombre[30];
        int cantidadDeEmpleados;
        int provincia;
    public:
        void cargar();
        void mostrar();
};

void Empresa::cargar(){
    cout << "INGRESE EL NOMBRE: ";
    cin >> nombre;
    cout << "INGRESE LA CANTIDAD DE EMPLEADOS: ";
    cin >> cantidadDeEmpleados;
    cout << "INGRESE LA PROVINCIA: ";
    cin >> provincia;
}

void Empresa::mostrar(){
    cout << "NOMBRE: " << nombre << endl;
    cout << "CANTIDAD DE EMPLEADOS: " << cantidadDeEmpleados << endl;
    cout << "PROVINCIA: " << provincia << endl;
}

void cargarEnArchivo(Empresa obj){
    FILE *p;

    p = fopen("empresa.dat","ab");

    if(p == nullptr){
        cout << "ERROR EN LA CARGA DE ARCHIVOS" << endl;
        return;
    }

    for(int i=1;i<=3;i++){
        obj.cargar();
        fwrite(&obj, sizeof obj, 1, p);
    }

    fclose(p);
}

void MostrarEnArchivo(Empresa obj){
    FILE *p;

    p = fopen("empresa.dat","rb");

    if(p == nullptr){
        cout << "ERROR EN LA CARGA DE ARCHIVOS" << endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1, p)){
        obj.mostrar();
    }
    
    fclose(p);
}

int main() {
   Empresa obj[3];

   //cargarEnArchivo(obj[3]);
   MostrarEnArchivo(obj[3]);

   return 0;
}
