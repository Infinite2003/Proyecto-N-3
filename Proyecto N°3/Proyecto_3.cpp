#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;

void generarOrdenado(vector<int>& aux, int c){

    for(int q = 1; q <= c; q++){

        aux.push_back(q);
    }
}

void generarInvOrdenado(vector<int>& aux, int c){

    for(int q = c; q > 0; q--){

        aux.push_back(q);
    }
}

void generarAleatorio(vector<int>& aux, int c){

    srand(time(0));

    int randome;

    for(int p = 0; p < c; p++){

        randome = rand()% 110000 + 1;

        aux.push_back(randome);
    }
}

void generarAleatorioSN(vector<int>& aux, int c){

    srand(time(0));

    int randome;

    for(int p = 0; p < c; p++){

        randome = rand()% 100000 + 1;
        bool existe = false;

        for(int num : aux){

            if(num == randome){

                existe = true;
                break;
            }
        }

        if(!existe){

            aux.push_back(randome);
        }
    }
}

void bubbleSort(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = 0; p < n - 1; p++){

        for(int q = 0; q < n-p-1; q++){

            if(aux[q] > aux[q+1]){

                int temp = aux[q];
                aux[q] = aux[q + 1];
                aux[q + 1] = temp;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void bubbleSortDescendente(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = 0; p < n - 1; p++){

        for(int q = 0; q < n-p-1; q++){

            if(aux[q] < aux[q+1]){

                int temp = aux[q];
                aux[q] = aux[q + 1];
                aux[q + 1] = temp;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void SelectionSort(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = 0; p < n - 1; p++){

        int myIndex = p;

        for(int q = p + 1; q < n; q++){

            if(aux[q] < aux[myIndex]){

                myIndex = q;
            }
        }

        int temp = aux[p];
        aux[p] = aux[myIndex];
        aux[myIndex] = temp;
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void SelectionSortDescendente(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = 0; p < n - 1; p++){

        int myIndex = p;

        for(int q = p + 1; q < n; q++){

            if(aux[q] > aux[myIndex]){

                myIndex = q;
            }
        }

        int temp = aux[p];
        aux[p] = aux[myIndex];
        aux[myIndex] = temp;
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void InsertionSort(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = 1; p < n; p++){

        int key = aux[p];
        int q = p - 1;

        while(q >= 0 && aux[q] > key){

            aux[q + 1] = aux[q];
            q--;
        }

        aux[q + 1] = key;
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void InsertionSortDescendente(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = 1; p < n; p++){

        int key = aux[p];
        int q = p - 1;

        while(q >= 0 && aux[q] < key){

            aux[q + 1] = aux[q];
            q--;
        }

        aux[q + 1] = key;
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();    
}

void ShellSort(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = n / 2; p > 0; p /= 2){

        for(int q = p; q < n; q++){

            int temp = aux[q];

            int r = q;

            while(r >= p && aux[r - p] > temp){

                aux[r] = aux[r - p];
                r-= p;
            }

            aux[r] = temp;
        }
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void ShellSortDescendente(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int p = n / 2; p > 0; p /= 2){

        for(int q = p; q < n; q++){

            int temp = aux[q];

            int r = q;

            while(r >= p && aux[r - p] < temp){

                aux[r] = aux[r - p];
                r-= p;
            }

            aux[r] = temp;
        }
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();    
}

void Merge(vector<int>& aux, int left, int middle, int right){

    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for(int p = 0; p < n1; p++){

        L[p] = aux[left + p];
    }

    for(int q = 0; q < n2; q++){

        R[q] = aux[middle + 1 + q];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){

        if(L[i] <= R[j]){

            aux[k] = L[i];
            i++;
        }

        else{

            aux[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1){

        aux[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){

        aux[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& aux, int left, int right){

    if(left < right){

        int middle = left + (right - left) / 2;

        MergeSort(aux,left,middle);
        MergeSort(aux,middle + 1, right);

        Merge(aux,left,middle,right);
    }
}

void MergeDescendente(vector<int>& aux, int left, int middle, int right){

    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for(int p = 0; p < n1; p++){

        L[p] = aux[left + p];
    }

    for(int q = 0; q < n2; q++){

        R[q] = aux[middle + 1 + q];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){

        if(L[i] >= R[j]){

            aux[k] = L[i];
            i++;
        }

        else{

            aux[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1){

        aux[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){

        aux[k] = R[j];
        j++;
        k++;
    }    
}

void MergeSortDescendente(vector<int>& aux, int left, int right){

    if(left < right){

        int middle = left + (right - left) / 2;

        MergeSortDescendente(aux,left,middle);
        MergeSortDescendente(aux,middle + 1, right);

        MergeDescendente(aux,left,middle,right);
    }
}

int ChoosePrivot(int low, int high){

    return low + (high - low) / 2;
}

int Partition(vector<int>& aux, int low, int high){

    int privotIndex = ChoosePrivot(low,high);
    int privot = aux[privotIndex];

    swap(aux[privotIndex], aux[high]);

    int i = low;

    for(int p = low; p < high; p++){

        if(aux[p] < privot){
            
            swap(aux[i], aux[p]);
            i++;
        }
    }

    swap(aux[i], aux[high]);

    return i;
}

void QuickSort(vector<int>& aux, int low, int high){

    if(low < high){

        int privotIndex = Partition(aux,low,high);

        QuickSort(aux,low,privotIndex - 1);
        QuickSort(aux,privotIndex + 1,high);            
    }
}

int ChoosePrivotDescendente(vector<int>& aux, int low, int high){

    int middle = low + (high - low) / 2;
    int privotIndex = -1;

    if ((aux[low] >= aux[middle] && aux[low] <= aux[high]) || (aux[low] <= aux[middle] && aux[low] >= aux[high])){

        privotIndex = low;
    }
        
    
    
    else if ((aux[middle] >= aux[low] && aux[middle] <= aux[high]) || (aux[middle] <= aux[low] && aux[middle] >= aux[high])){

        privotIndex = middle;
    }

    
    
    else{

        privotIndex = high;
    }
        

    return privotIndex;

}

int PartitionDescendente(vector<int>& aux, int low, int high){

    int privotIndex = ChoosePrivotDescendente(aux,low,high);
    int privot = aux[privotIndex];

    swap(aux[privotIndex], aux[high]);
    int i = low - 1;

    for(int p = low; p < high; p++){

        if(aux[p] >= privot){

            i++;
            swap(aux[i], aux[p]);
        }
    }

    swap(aux[i + 1], aux[high]);

    return i + 1;
}

void QuickSortDescendente(vector<int>& aux, int low, int high){

    if(low < high){

        int privotIndex = PartitionDescendente(aux,low,high);

        QuickSortDescendente(aux,low,privotIndex - 1);
        QuickSortDescendente(aux,privotIndex + 1,high);
    }    
}

void Heapify(vector<int>& aux, int n, int i){

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && aux[left] > aux[largest]){

        largest = left;
    }

    if(right < n && aux[right] > aux[largest]){

        largest = right;
    }

    if(largest != i){

        swap(aux[i], aux[largest]);
        Heapify(aux,n,largest);
    }
}

void HeapSort(vector<int>& aux, double& ti){

    int n = aux.size();

    auto start = chrono::high_resolution_clock::now();

    for(int i = n / 2 - 1; i >= 0; i--){

        Heapify(aux,n,i);
    }

    for(int i = n - 1; i > 0; i--){

        swap(aux[0], aux[i]);

        Heapify(aux,i,0);
    }

    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - start).count();
}

void HeapifyDescendente(vector<int>& aux, int n, int i){

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && aux[left] < aux[largest]){

        largest = left;
    }

    if(right < n && aux[right] < aux[largest]){

        largest = right;
    }

    if(largest != i){

        swap(aux[i], aux[largest]);
        HeapifyDescendente(aux,n,largest);
    }
}

void HeapSortDescendente(vector<int>& aux, double& ti){

    int n = aux.size();

    auto star = chrono::high_resolution_clock::now();

    for(int i = n / 2 - 1; i >= 0; i--){

        HeapifyDescendente(aux,n,i);
    }

    for(int i = n - 1; i > 0; i--){

        swap(aux[0], aux[i]);

        HeapifyDescendente(aux,i,0);
    }
    
    auto end = chrono::high_resolution_clock::now();

    ti = chrono::duration<double>(end - star).count();
}

void comparar(double IS, double SS, double BS, double SHS, double MS, double QS, double HS){

    unordered_map<string,double> tiempos = {

        {"InsertionSort", IS},
        {"SelecctionSort",SS},
        {"BubbleSort",BS},
        {"ShellSort",SHS},
        {"MergeSort",MS},
        {"QuickSort",QS},
        {"HeapSort",HS}
    };

    double menor = numeric_limits<double>::max();
    string nombre = "";

    for(const auto& variable : tiempos){

        if(variable.second < menor){

            menor = variable.second;
            nombre = variable.first;
        }
    }

    cout<<"El ganador es: "<<nombre<<" con: "<<menor<< "segundos"<<endl;
}

int main(){

    srand(time(0));

    vector<int> Ordenado;
    vector<int> InvOrdenado;
    vector<int> Aleatorio;
    vector<int> AlteatorioSinRepetir;

    vector<int> Copia1;
    vector<int> Copia2;
    vector<int> Copia3;
    vector<int> Copia4;
    vector<int> Copia5;
    vector<int> Copia6;
    vector<int> Copia7;

    double TiempoIS_1;
    double TiempoSS_1;
    double TiempoBS_1;
    double TiempoSHS_1;
    double TiempoMS_1;
    double TiempoQS_1;
    double TiempoHS_1;

    double TiempoIS_2;
    double TiempoSS_2;
    double TiempoBS_2;
    double TiempoSHS_2;
    double TiempoMS_2;
    double TiempoQS_2;
    double TiempoHS_2; 

    double TiempoIS_3;
    double TiempoSS_3;
    double TiempoBS_3;
    double TiempoSHS_3;
    double TiempoMS_3;
    double TiempoQS_3;
    double TiempoHS_3;

    double TiempoIS_4;
    double TiempoSS_4;
    double TiempoBS_4;
    double TiempoSHS_4;
    double TiempoMS_4;
    double TiempoQS_4;
    double TiempoHS_4;  

    int opcion;
    int precaucion = 0;
    int carrera1 = rand()% 10000 + 90000;
    int carrera2 = rand()% 20000 + 50000; 
    int carrera3 = rand()% 7500 + 7500;

 

    while(precaucion == 0){

        cout<<"Carrera de algoritmos"<<endl;
        cout<<"1: Ascendente."<<endl;
        cout<<"2: Descendente."<<endl;
        
        cin>>opcion;

        if(opcion == 1){

            cout<<"Opcion elegida: Ascendente"<<endl;
            precaucion = 1;
        }

        else if(opcion == 2){

            cout<<"Opcion elegida: Descendente"<<endl;
            precaucion = 1;
        }

        else{

            cout<<"Ingrese una opcion valida"<<endl;
        }
    }

    cout<<"Numero carrera 1: "<<carrera1<<endl;
    cout<<"Numero carrera 2: "<<carrera2<<endl;
    cout<<"Numero Carrera 3: "<<carrera3<<endl;

    if(opcion == 1){

        cout<<"Carrera 1: Modo Ordenado"<<endl;        
        //carrera con Ordenado

        generarOrdenado(Ordenado,carrera1);
        generarInvOrdenado(InvOrdenado,carrera1);
        generarAleatorio(Aleatorio,carrera1);
        generarAleatorioSN(AlteatorioSinRepetir,30000);

        Copia1 = Ordenado;
        Copia2 = Ordenado;
        Copia3 = Ordenado;
        Copia4 = Ordenado;
        Copia5 = Ordenado;
        Copia6 = Ordenado;
        Copia7 = Ordenado;

        bubbleSort(Copia1, TiempoBS_1);

        cout<<"BubbleSort: "<<TiempoBS_1<<" segundos"<<endl;

        InsertionSort(Copia2,TiempoIS_1);

        cout<<"InsertionSort: "<<TiempoIS_1<<" segundos"<<endl;
        
        SelectionSort(Copia3,TiempoSS_1);

        cout<<"SelectionSort: "<<TiempoSS_1<<" segundos"<<endl;
        
        ShellSort(Copia4,TiempoSHS_1);

        cout<<"ShellSort: "<<TiempoSHS_1<<" segundos"<<endl;

        auto start1 = chrono::high_resolution_clock::now();
        MergeSort(Copia5,0,Ordenado.size() - 1);
        auto end1 = chrono::high_resolution_clock::now();        
        TiempoMS_1 = chrono::duration<double>(end1 - start1).count();

        cout<<"MergeSort: "<<TiempoMS_1<<" segundos"<<endl;

        HeapSort(Copia6,TiempoHS_1);

        cout<<"HeapSort: "<<TiempoHS_1<<" segundos"<<endl;

        auto start2 = chrono::high_resolution_clock::now();
        QuickSort(Ordenado,0,Ordenado.size() - 1);
        auto end2 = chrono::high_resolution_clock::now();
        TiempoQS_1 = chrono::duration<double>(end2 - start2).count();

        cout<<"QuickSort: "<<TiempoQS_1<<" segundos"<<endl;

        comparar(TiempoIS_1,TiempoSS_1,TiempoBS_1,TiempoSHS_1,TiempoMS_1,TiempoQS_1,TiempoHS_1);

        Copia1 = InvOrdenado;
        Copia2 = InvOrdenado;
        Copia3 = InvOrdenado;
        Copia4 = InvOrdenado;
        Copia5 = InvOrdenado;
        Copia6 = InvOrdenado;
        Copia7 = InvOrdenado;

        //carrera con inversamente ordenado
        cout<<"Carrera 1:Modo Inversamente Ordenado:"<<endl;

        bubbleSort(Copia1, TiempoBS_2);

        cout<<"BubbleSort: "<<TiempoBS_2<<" segundos"<<endl;

        InsertionSort(Copia2,TiempoIS_2);

        cout<<"InsertionSort: "<<TiempoIS_2<<" segundos"<<endl;
        
        SelectionSort(Copia3,TiempoSS_2);

        cout<<"SelectionSort: "<<TiempoSS_2<<" segundos"<<endl;
        
        ShellSort(Copia4,TiempoSHS_2);

        cout<<"ShellSort: "<<TiempoSHS_2<<" segundos"<<endl;

        HeapSort(Copia5,TiempoHS_2);

        cout<<"HeapSort: "<<TiempoHS_2<<" segundos"<<endl;

        auto start3 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end3 = chrono::high_resolution_clock::now();
        TiempoMS_2 = chrono::duration<double>(end3 - start3).count();

        cout<<"MergeSort: "<<TiempoMS_2<<" segundos"<<endl;

        auto start4 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end4 = chrono::high_resolution_clock::now();
        TiempoQS_2 = chrono::duration<double>(end4 - start4).count();

        cout<<"QuickSort: "<<TiempoQS_2<<" segundos"<<endl; 

        comparar(TiempoIS_2,TiempoSS_2,TiempoBS_2,TiempoSHS_2,TiempoMS_2,TiempoQS_2,TiempoHS_2);
        
        Copia1 = Aleatorio;
        Copia2 = Aleatorio;
        Copia3 = Aleatorio;
        Copia4 = Aleatorio;
        Copia5 = Aleatorio;
        Copia6 = Aleatorio;
        Copia7 = Aleatorio;        

        cout<<"Carrera 1: Modo Aleatorio:"<<endl;

        bubbleSort(Copia1, TiempoBS_3);

        cout<<"BubbleSort: "<<TiempoBS_3<<" segundos"<<endl;

        InsertionSort(Copia2,TiempoIS_3);

        cout<<"InsertionSort: "<<TiempoIS_3<<" segundos"<<endl;
        
        SelectionSort(Copia3,TiempoSS_3);

        cout<<"SelectionSort: "<<TiempoSS_3<<" segundos"<<endl;
        
        ShellSort(Copia4,TiempoSHS_3);

        cout<<"ShellSort: "<<TiempoSHS_3<<" segundos"<<endl;

        HeapSort(Copia5,TiempoHS_3);

        cout<<"HeapSort: "<<TiempoHS_3<<" segundos"<<endl;

        auto start5 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end5 = chrono::high_resolution_clock::now();
        TiempoMS_3 = chrono::duration<double>(end5 - start5).count();

        cout<<"MergeSort: "<<TiempoMS_3<<" segundos"<<endl;

        auto start6 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end6 = chrono::high_resolution_clock::now();
        TiempoQS_3 = chrono::duration<double>(end6 - start6).count();

        cout<<"QuickSort: "<<TiempoQS_3<<" segundos"<<endl;

        comparar(TiempoIS_3,TiempoSS_3,TiempoBS_3,TiempoSHS_3,TiempoMS_3,TiempoQS_3,TiempoHS_3);

        Copia1 = AlteatorioSinRepetir;
        Copia2 = AlteatorioSinRepetir;
        Copia3 = AlteatorioSinRepetir;
        Copia4 = AlteatorioSinRepetir;
        Copia5 = AlteatorioSinRepetir;
        Copia6 = AlteatorioSinRepetir;
        Copia7 = AlteatorioSinRepetir;

        cout<<"Carrera 1: Aleatorio Sin repeticion"<<endl;

        bubbleSort(Copia1, TiempoBS_4);

        cout<<"BubbleSort: "<<TiempoBS_4<<" segundos"<<endl;

        InsertionSort(Copia2,TiempoIS_4);

        cout<<"InsertionSort: "<<TiempoIS_4<<" segundos"<<endl;
        
        SelectionSort(Copia3,TiempoSS_4);

        cout<<"SelectionSort: "<<TiempoSS_4<<" segundos"<<endl;
        
        ShellSort(Copia4,TiempoSHS_4);

        cout<<"ShellSort: "<<TiempoSHS_4<<" segundos"<<endl;

        HeapSort(Copia5,TiempoHS_4);

        cout<<"HeapSort: "<<TiempoHS_4<<" segundos"<<endl;

        auto start7 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end7 = chrono::high_resolution_clock::now();
        TiempoMS_4 = chrono::duration<double>(end7 - start7).count();

        cout<<"MergeSort: "<<TiempoMS_4<<" segundos"<<endl;

        auto start8 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end8 = chrono::high_resolution_clock::now();
        TiempoQS_4 = chrono::duration<double>(end8 - start8).count();  

        cout<<"QuickSort: "<<TiempoQS_4<<" segundos"<<endl;

        comparar(TiempoIS_4,TiempoSS_4,TiempoBS_4,TiempoSHS_4,TiempoMS_4,TiempoQS_4,TiempoHS_4);

        Ordenado.clear();
        InvOrdenado.clear();
        Aleatorio.clear();
        AlteatorioSinRepetir.clear();

        cout<<"Carrera 2: Modo Ordenado:"<<endl;

        generarOrdenado(Ordenado,carrera2);
        generarInvOrdenado(InvOrdenado,carrera2);
        generarAleatorio(Aleatorio,carrera2);
        generarAleatorioSN(AlteatorioSinRepetir,30000);

        Copia1 = Ordenado;
        Copia2 = Ordenado;
        Copia3 = Ordenado;
        Copia4 = Ordenado;
        Copia5 = Ordenado;
        Copia6 = Ordenado;
        Copia7 = Ordenado;

        bubbleSort(Copia1, TiempoBS_1);

        cout<<"BubbleSort: "<<TiempoBS_1<<" segundos"<<endl;

        InsertionSort(Copia2,TiempoIS_1);
        
        cout<<"InsertionSort: "<<TiempoIS_1<<" segundos"<<endl;

        SelectionSort(Copia3,TiempoSS_1);

        cout<<"SelectionSort: "<<TiempoSS_1<<" segundos"<<endl;
        
        ShellSort(Copia4,TiempoSHS_1);

        cout<<"ShellSort: "<<TiempoSHS_1<<" segundos"<<endl;

        auto start9 = chrono::high_resolution_clock::now();
        MergeSort(Copia5,0,Ordenado.size() - 1);
        auto end9 = chrono::high_resolution_clock::now();        
        TiempoMS_1 = chrono::duration<double>(end9 - start9).count();

        cout<<"MergeSort: "<<TiempoMS_1<<" segundos"<<endl;

        HeapSort(Copia6,TiempoHS_1);

        cout<<"HeapSort: "<<TiempoHS_1<<" segundos"<<endl;

        auto start10 = chrono::high_resolution_clock::now();
        QuickSort(Ordenado,0,Ordenado.size() - 1);
        auto end10 = chrono::high_resolution_clock::now();
        TiempoQS_1 = chrono::duration<double>(end10 - start10).count();

        cout<<"QuickSort: "<<TiempoQS_1<<" segundos"<<endl;

        comparar(TiempoIS_1,TiempoSS_1,TiempoBS_1,TiempoSHS_1,TiempoMS_1,TiempoQS_1,TiempoHS_1);

        Copia1 = InvOrdenado;
        Copia2 = InvOrdenado;
        Copia3 = InvOrdenado;
        Copia4 = InvOrdenado;
        Copia5 = InvOrdenado;
        Copia6 = InvOrdenado;
        Copia7 = InvOrdenado;

        //carrera con inversamente ordenado
        cout<<"Carrera 2:Modo Inversamente Ordenado:"<<endl;

        bubbleSort(Copia1, TiempoBS_2);

        cout<<"BubbleSort: "<<TiempoBS_2<<" segundos"<<endl;

        InsertionSort(Copia2,TiempoIS_2);
        
        SelectionSort(Copia3,TiempoSS_2);
        
        ShellSort(Copia4,TiempoSHS_2);

        HeapSort(Copia5,TiempoHS_2);

        auto start11 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end11 = chrono::high_resolution_clock::now();
        TiempoMS_2 = chrono::duration<double>(end11 - start11).count();

        auto start12 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end12 = chrono::high_resolution_clock::now();
        TiempoQS_2 = chrono::duration<double>(end12 - start12).count(); 

        comparar(TiempoIS_2,TiempoSS_2,TiempoBS_2,TiempoSHS_2,TiempoMS_2,TiempoQS_2,TiempoHS_2);
        
        Copia1 = Aleatorio;
        Copia2 = Aleatorio;
        Copia3 = Aleatorio;
        Copia4 = Aleatorio;
        Copia5 = Aleatorio;
        Copia6 = Aleatorio;
        Copia7 = Aleatorio;        

        cout<<"Carrera 2: Modo Aleatorio:"<<endl;

        bubbleSort(Copia1, TiempoBS_3);

        InsertionSort(Copia2,TiempoIS_3);
        
        SelectionSort(Copia3,TiempoSS_3);
        
        ShellSort(Copia4,TiempoSHS_3);

        HeapSort(Copia5,TiempoHS_3);

        auto start13 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end13 = chrono::high_resolution_clock::now();
        TiempoMS_3 = chrono::duration<double>(end13 - start13).count();

        auto start14 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end14 = chrono::high_resolution_clock::now();
        TiempoQS_3 = chrono::duration<double>(end14 - start14).count();

        comparar(TiempoIS_3,TiempoSS_3,TiempoBS_3,TiempoSHS_3,TiempoMS_3,TiempoQS_3,TiempoHS_3);

        Copia1 = AlteatorioSinRepetir;
        Copia2 = AlteatorioSinRepetir;
        Copia3 = AlteatorioSinRepetir;
        Copia4 = AlteatorioSinRepetir;
        Copia5 = AlteatorioSinRepetir;
        Copia6 = AlteatorioSinRepetir;
        Copia7 = AlteatorioSinRepetir;

        cout<<"Carrera 2: Aleatorio Sin repeticion"<<endl;

        bubbleSort(Copia1, TiempoBS_4);

        InsertionSort(Copia2,TiempoIS_4);
        
        SelectionSort(Copia3,TiempoSS_4);
        
        ShellSort(Copia4,TiempoSHS_4);

        HeapSort(Copia5,TiempoHS_4);

        auto start15 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end15 = chrono::high_resolution_clock::now();
        TiempoMS_4 = chrono::duration<double>(end15 - start15).count();

        auto start16 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end16 = chrono::high_resolution_clock::now();
        TiempoQS_4 = chrono::duration<double>(end16 - start16).count();  

        comparar(TiempoIS_4,TiempoSS_4,TiempoBS_4,TiempoSHS_4,TiempoMS_4,TiempoQS_4,TiempoHS_4);

        Ordenado.clear();
        InvOrdenado.clear();
        Aleatorio.clear();
        AlteatorioSinRepetir.clear();

        
        cout<<"Carrera 3: Modo Ordenado:"<<endl;

        generarOrdenado(Ordenado,carrera3);
        generarInvOrdenado(InvOrdenado,carrera3);
        generarAleatorio(Aleatorio,carrera3);
        generarAleatorioSN(AlteatorioSinRepetir,carrera3);

        Copia1 = Ordenado;
        Copia2 = Ordenado;
        Copia3 = Ordenado;
        Copia4 = Ordenado;
        Copia5 = Ordenado;
        Copia6 = Ordenado;
        Copia7 = Ordenado;

        bubbleSort(Copia1, TiempoBS_1);

        InsertionSort(Copia2,TiempoIS_1);
        
        SelectionSort(Copia3,TiempoSS_1);
        
        ShellSort(Copia4,TiempoSHS_1);

        auto start17 = chrono::high_resolution_clock::now();
        MergeSort(Copia5,0,Ordenado.size() - 1);
        auto end17 = chrono::high_resolution_clock::now();        
        TiempoMS_1 = chrono::duration<double>(end17 - start17).count();

        HeapSort(Copia6,TiempoHS_1);

        auto start18 = chrono::high_resolution_clock::now();
        QuickSort(Ordenado,0,Ordenado.size() - 1);
        auto end18 = chrono::high_resolution_clock::now();
        TiempoQS_1 = chrono::duration<double>(end18 - start18).count();

        comparar(TiempoIS_1,TiempoSS_1,TiempoBS_1,TiempoSHS_1,TiempoMS_1,TiempoQS_1,TiempoHS_1);

        Copia1 = InvOrdenado;
        Copia2 = InvOrdenado;
        Copia3 = InvOrdenado;
        Copia4 = InvOrdenado;
        Copia5 = InvOrdenado;
        Copia6 = InvOrdenado;
        Copia7 = InvOrdenado;

        //carrera con inversamente ordenado
        cout<<"Carrera 3:Modo Inversamente Ordenado:"<<endl;

        bubbleSort(Copia1, TiempoBS_2);

        InsertionSort(Copia2,TiempoIS_2);
        
        SelectionSort(Copia3,TiempoSS_2);
        
        ShellSort(Copia4,TiempoSHS_2);

        HeapSort(Copia5,TiempoHS_2);

        auto start19 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end19 = chrono::high_resolution_clock::now();
        TiempoMS_2 = chrono::duration<double>(end19 - start19).count();

        auto start20 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end20 = chrono::high_resolution_clock::now();
        TiempoQS_2 = chrono::duration<double>(end20 - start20).count(); 

        comparar(TiempoIS_2,TiempoSS_2,TiempoBS_2,TiempoSHS_2,TiempoMS_2,TiempoQS_2,TiempoHS_2);
        
        Copia1 = Aleatorio;
        Copia2 = Aleatorio;
        Copia3 = Aleatorio;
        Copia4 = Aleatorio;
        Copia5 = Aleatorio;
        Copia6 = Aleatorio;
        Copia7 = Aleatorio;        

        cout<<"Carrera 3: Modo Aleatorio:"<<endl;

        bubbleSort(Copia1, TiempoBS_3);

        InsertionSort(Copia2,TiempoIS_3);
        
        SelectionSort(Copia3,TiempoSS_3);
        
        ShellSort(Copia4,TiempoSHS_3);

        HeapSort(Copia5,TiempoHS_3);

        auto start21 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end21 = chrono::high_resolution_clock::now();
        TiempoMS_3 = chrono::duration<double>(end21 - start21).count();

        auto start22 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end22 = chrono::high_resolution_clock::now();
        TiempoQS_3 = chrono::duration<double>(end22 - start22).count();

        comparar(TiempoIS_3,TiempoSS_3,TiempoBS_3,TiempoSHS_3,TiempoMS_3,TiempoQS_3,TiempoHS_3);

        Copia1 = AlteatorioSinRepetir;
        Copia2 = AlteatorioSinRepetir;
        Copia3 = AlteatorioSinRepetir;
        Copia4 = AlteatorioSinRepetir;
        Copia5 = AlteatorioSinRepetir;
        Copia6 = AlteatorioSinRepetir;
        Copia7 = AlteatorioSinRepetir;

        cout<<"Carrera 3: Aleatorio Sin repeticion"<<endl;

        bubbleSort(Copia1, TiempoBS_4);

        InsertionSort(Copia2,TiempoIS_4);
        
        SelectionSort(Copia3,TiempoSS_4);
        
        ShellSort(Copia4,TiempoSHS_4);

        HeapSort(Copia5,TiempoHS_4);

        auto start23 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end23 = chrono::high_resolution_clock::now();
        TiempoMS_4 = chrono::duration<double>(end23 - start23).count();

        auto start24 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end24 = chrono::high_resolution_clock::now();
        TiempoQS_4 = chrono::duration<double>(end24 - start24).count();  

        comparar(TiempoIS_4,TiempoSS_4,TiempoBS_4,TiempoSHS_4,TiempoMS_4,TiempoQS_4,TiempoHS_4);

        Ordenado.clear();
        InvOrdenado.clear();
        Aleatorio.clear();
        AlteatorioSinRepetir.clear();

    }

    if(opcion == 2){

        cout<<"Carrera 1: Modo Ordenado:"<<endl;

        generarInvOrdenado(Ordenado,carrera2);
        generarOrdenado(InvOrdenado,carrera2);
        generarAleatorio(Aleatorio,carrera2);
        generarAleatorioSN(AlteatorioSinRepetir,30000);

        Copia1 = Ordenado;
        Copia2 = Ordenado;
        Copia3 = Ordenado;
        Copia4 = Ordenado;
        Copia5 = Ordenado;
        Copia6 = Ordenado;
        Copia7 = Ordenado;

        bubbleSort(Copia1, TiempoBS_1);

        InsertionSort(Copia2,TiempoIS_1);
        
        SelectionSort(Copia3,TiempoSS_1);
        
        ShellSort(Copia4,TiempoSHS_1);

        auto start1 = chrono::high_resolution_clock::now();
        MergeSort(Copia5,0,Ordenado.size() - 1);
        auto end1 = chrono::high_resolution_clock::now();        
        TiempoMS_1 = chrono::duration<double>(end1 - start1).count();

        HeapSort(Copia6,TiempoHS_1);

        auto start2 = chrono::high_resolution_clock::now();
        QuickSort(Ordenado,0,Ordenado.size() - 1);
        auto end2 = chrono::high_resolution_clock::now();
        TiempoQS_1 = chrono::duration<double>(end2 - start2).count();

        comparar(TiempoIS_1,TiempoSS_1,TiempoBS_1,TiempoSHS_1,TiempoMS_1,TiempoQS_1,TiempoHS_1);

        Copia1 = InvOrdenado;
        Copia2 = InvOrdenado;
        Copia3 = InvOrdenado;
        Copia4 = InvOrdenado;
        Copia5 = InvOrdenado;
        Copia6 = InvOrdenado;
        Copia7 = InvOrdenado;

        //carrera con inversamente ordenado
        cout<<"Carrera 1: Modo Inversamente Ordenado:"<<endl;

        bubbleSort(Copia1, TiempoBS_2);

        InsertionSort(Copia2,TiempoIS_2);
        
        SelectionSort(Copia3,TiempoSS_2);
        
        ShellSort(Copia4,TiempoSHS_2);

        HeapSort(Copia5,TiempoHS_2);

        auto start3 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end3 = chrono::high_resolution_clock::now();
        TiempoMS_2 = chrono::duration<double>(end3 - start3).count();

        auto start4 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end4 = chrono::high_resolution_clock::now();
        TiempoQS_2 = chrono::duration<double>(end4 - start4).count(); 

        comparar(TiempoIS_2,TiempoSS_2,TiempoBS_2,TiempoSHS_2,TiempoMS_2,TiempoQS_2,TiempoHS_2);
        
        Copia1 = Aleatorio;
        Copia2 = Aleatorio;
        Copia3 = Aleatorio;
        Copia4 = Aleatorio;
        Copia5 = Aleatorio;
        Copia6 = Aleatorio;
        Copia7 = Aleatorio;        

        cout<<"Carrera 1: Modo Aleatorio:"<<endl;

        bubbleSort(Copia1, TiempoBS_3);

        InsertionSort(Copia2,TiempoIS_3);
        
        SelectionSort(Copia3,TiempoSS_3);
        
        ShellSort(Copia4,TiempoSHS_3);

        HeapSort(Copia5,TiempoHS_3);

        auto start5 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end5 = chrono::high_resolution_clock::now();
        TiempoMS_3 = chrono::duration<double>(end5 - start5).count();

        auto start6 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end6 = chrono::high_resolution_clock::now();
        TiempoQS_3 = chrono::duration<double>(end6 - start6).count();

        comparar(TiempoIS_3,TiempoSS_3,TiempoBS_3,TiempoSHS_3,TiempoMS_3,TiempoQS_3,TiempoHS_3);

        Copia1 = AlteatorioSinRepetir;
        Copia2 = AlteatorioSinRepetir;
        Copia3 = AlteatorioSinRepetir;
        Copia4 = AlteatorioSinRepetir;
        Copia5 = AlteatorioSinRepetir;
        Copia6 = AlteatorioSinRepetir;
        Copia7 = AlteatorioSinRepetir;

        cout<<"Carrera 1: Aleatorio Sin repeticion:"<<endl;

        bubbleSort(Copia1, TiempoBS_4);

        InsertionSort(Copia2,TiempoIS_4);
        
        SelectionSort(Copia3,TiempoSS_4);
        
        ShellSort(Copia4,TiempoSHS_4);

        HeapSort(Copia5,TiempoHS_4);

        auto start7 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end7 = chrono::high_resolution_clock::now();
        TiempoMS_4 = chrono::duration<double>(end7 - start7).count();

        auto start8 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end8 = chrono::high_resolution_clock::now();
        TiempoQS_4 = chrono::duration<double>(end8 - start8).count();  

        comparar(TiempoIS_4,TiempoSS_4,TiempoBS_4,TiempoSHS_4,TiempoMS_4,TiempoQS_4,TiempoHS_4);

        Ordenado.clear();
        InvOrdenado.clear();
        Aleatorio.clear();
        AlteatorioSinRepetir.clear();

        cout<<"Carrera 2: Modo Ordenado:"<<endl;

        generarOrdenado(Ordenado,carrera2);
        generarInvOrdenado(InvOrdenado,carrera2);
        generarAleatorio(Aleatorio,carrera2);
        generarAleatorioSN(AlteatorioSinRepetir,30000);

        Copia1 = Ordenado;
        Copia2 = Ordenado;
        Copia3 = Ordenado;
        Copia4 = Ordenado;
        Copia5 = Ordenado;
        Copia6 = Ordenado;
        Copia7 = Ordenado;

        bubbleSort(Copia1, TiempoBS_1);

        InsertionSort(Copia2,TiempoIS_1);
        
        SelectionSort(Copia3,TiempoSS_1);
        
        ShellSort(Copia4,TiempoSHS_1);

        auto start9 = chrono::high_resolution_clock::now();
        MergeSort(Copia5,0,Ordenado.size() - 1);
        auto end9 = chrono::high_resolution_clock::now();        
        TiempoMS_1 = chrono::duration<double>(end9 - start9).count();

        HeapSort(Copia6,TiempoHS_1);

        auto start10 = chrono::high_resolution_clock::now();
        QuickSort(Ordenado,0,Ordenado.size() - 1);
        auto end10 = chrono::high_resolution_clock::now();
        TiempoQS_1 = chrono::duration<double>(end10 - start10).count();

        comparar(TiempoIS_1,TiempoSS_1,TiempoBS_1,TiempoSHS_1,TiempoMS_1,TiempoQS_1,TiempoHS_1);

        Copia1 = InvOrdenado;
        Copia2 = InvOrdenado;
        Copia3 = InvOrdenado;
        Copia4 = InvOrdenado;
        Copia5 = InvOrdenado;
        Copia6 = InvOrdenado;
        Copia7 = InvOrdenado;

        //carrera con inversamente ordenado
        cout<<"Carrera 2:Modo Inversamente Ordenado:"<<endl;

        bubbleSort(Copia1, TiempoBS_2);

        InsertionSort(Copia2,TiempoIS_2);
        
        SelectionSort(Copia3,TiempoSS_2);
        
        ShellSort(Copia4,TiempoSHS_2);

        HeapSort(Copia5,TiempoHS_2);

        auto start11 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end11 = chrono::high_resolution_clock::now();
        TiempoMS_2 = chrono::duration<double>(end11 - start11).count();

        auto start12 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end12 = chrono::high_resolution_clock::now();
        TiempoQS_2 = chrono::duration<double>(end12 - start12).count(); 

        comparar(TiempoIS_2,TiempoSS_2,TiempoBS_2,TiempoSHS_2,TiempoMS_2,TiempoQS_2,TiempoHS_2);
        
        Copia1 = Aleatorio;
        Copia2 = Aleatorio;
        Copia3 = Aleatorio;
        Copia4 = Aleatorio;
        Copia5 = Aleatorio;
        Copia6 = Aleatorio;
        Copia7 = Aleatorio;        

        cout<<"Carrera 2: Modo Aleatorio:"<<endl;

        bubbleSort(Copia1, TiempoBS_3);

        InsertionSort(Copia2,TiempoIS_3);
        
        SelectionSort(Copia3,TiempoSS_3);
        
        ShellSort(Copia4,TiempoSHS_3);

        HeapSort(Copia5,TiempoHS_3);

        auto start13 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end13 = chrono::high_resolution_clock::now();
        TiempoMS_3 = chrono::duration<double>(end13 - start13).count();

        auto start14 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end14 = chrono::high_resolution_clock::now();
        TiempoQS_3 = chrono::duration<double>(end14 - start14).count();

        comparar(TiempoIS_3,TiempoSS_3,TiempoBS_3,TiempoSHS_3,TiempoMS_3,TiempoQS_3,TiempoHS_3);

        Copia1 = AlteatorioSinRepetir;
        Copia2 = AlteatorioSinRepetir;
        Copia3 = AlteatorioSinRepetir;
        Copia4 = AlteatorioSinRepetir;
        Copia5 = AlteatorioSinRepetir;
        Copia6 = AlteatorioSinRepetir;
        Copia7 = AlteatorioSinRepetir;

        cout<<"Carrera 2: Aleatorio Sin repeticion"<<endl;

        bubbleSort(Copia1, TiempoBS_4);

        InsertionSort(Copia2,TiempoIS_4);
        
        SelectionSort(Copia3,TiempoSS_4);
        
        ShellSort(Copia4,TiempoSHS_4);

        HeapSort(Copia5,TiempoHS_4);

        auto start15 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end15 = chrono::high_resolution_clock::now();
        TiempoMS_4 = chrono::duration<double>(end15 - start15).count();

        auto start16 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end16 = chrono::high_resolution_clock::now();
        TiempoQS_4 = chrono::duration<double>(end16 - start16).count();  

        comparar(TiempoIS_4,TiempoSS_4,TiempoBS_4,TiempoSHS_4,TiempoMS_4,TiempoQS_4,TiempoHS_4);

        Ordenado.clear();
        InvOrdenado.clear();
        Aleatorio.clear();
        AlteatorioSinRepetir.clear();

        
        cout<<"Carrera 3: Modo Ordenado:"<<endl;

        generarOrdenado(Ordenado,carrera3);
        generarInvOrdenado(InvOrdenado,carrera3);
        generarAleatorio(Aleatorio,carrera3);
        generarAleatorioSN(AlteatorioSinRepetir,carrera3);

        Copia1 = Ordenado;
        Copia2 = Ordenado;
        Copia3 = Ordenado;
        Copia4 = Ordenado;
        Copia5 = Ordenado;
        Copia6 = Ordenado;
        Copia7 = Ordenado;

        bubbleSort(Copia1, TiempoBS_1);

        InsertionSort(Copia2,TiempoIS_1);
        
        SelectionSort(Copia3,TiempoSS_1);
        
        ShellSort(Copia4,TiempoSHS_1);

        auto start17 = chrono::high_resolution_clock::now();
        MergeSort(Copia5,0,Ordenado.size() - 1);
        auto end17 = chrono::high_resolution_clock::now();        
        TiempoMS_1 = chrono::duration<double>(end17 - start17).count();

        HeapSort(Copia6,TiempoHS_1);

        auto start18 = chrono::high_resolution_clock::now();
        QuickSort(Ordenado,0,Ordenado.size() - 1);
        auto end18 = chrono::high_resolution_clock::now();
        TiempoQS_1 = chrono::duration<double>(end18 - start18).count();

        comparar(TiempoIS_1,TiempoSS_1,TiempoBS_1,TiempoSHS_1,TiempoMS_1,TiempoQS_1,TiempoHS_1);

        Copia1 = InvOrdenado;
        Copia2 = InvOrdenado;
        Copia3 = InvOrdenado;
        Copia4 = InvOrdenado;
        Copia5 = InvOrdenado;
        Copia6 = InvOrdenado;
        Copia7 = InvOrdenado;

        //carrera con inversamente ordenado
        cout<<"Carrera 3:Modo Inversamente Ordenado:"<<endl;

        bubbleSort(Copia1, TiempoBS_2);

        InsertionSort(Copia2,TiempoIS_2);
        
        SelectionSort(Copia3,TiempoSS_2);
        
        ShellSort(Copia4,TiempoSHS_2);

        HeapSort(Copia5,TiempoHS_2);

        auto start19 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end19 = chrono::high_resolution_clock::now();
        TiempoMS_2 = chrono::duration<double>(end19 - start19).count();

        auto start20 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end20 = chrono::high_resolution_clock::now();
        TiempoQS_2 = chrono::duration<double>(end20 - start20).count(); 

        comparar(TiempoIS_2,TiempoSS_2,TiempoBS_2,TiempoSHS_2,TiempoMS_2,TiempoQS_2,TiempoHS_2);
        
        Copia1 = Aleatorio;
        Copia2 = Aleatorio;
        Copia3 = Aleatorio;
        Copia4 = Aleatorio;
        Copia5 = Aleatorio;
        Copia6 = Aleatorio;
        Copia7 = Aleatorio;        

        cout<<"Carrera 3: Modo Aleatorio:"<<endl;

        bubbleSort(Copia1, TiempoBS_3);

        InsertionSort(Copia2,TiempoIS_3);
        
        SelectionSort(Copia3,TiempoSS_3);
        
        ShellSort(Copia4,TiempoSHS_3);

        HeapSort(Copia5,TiempoHS_3);

        auto start21 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end21 = chrono::high_resolution_clock::now();
        TiempoMS_3 = chrono::duration<double>(end21 - start21).count();

        auto start22 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end22 = chrono::high_resolution_clock::now();
        TiempoQS_3 = chrono::duration<double>(end22 - start22).count();

        comparar(TiempoIS_3,TiempoSS_3,TiempoBS_3,TiempoSHS_3,TiempoMS_3,TiempoQS_3,TiempoHS_3);

        Copia1 = AlteatorioSinRepetir;
        Copia2 = AlteatorioSinRepetir;
        Copia3 = AlteatorioSinRepetir;
        Copia4 = AlteatorioSinRepetir;
        Copia5 = AlteatorioSinRepetir;
        Copia6 = AlteatorioSinRepetir;
        Copia7 = AlteatorioSinRepetir;

        cout<<"Carrera 3: Aleatorio Sin repeticion"<<endl;

        bubbleSort(Copia1, TiempoBS_4);

        InsertionSort(Copia2,TiempoIS_4);
        
        SelectionSort(Copia3,TiempoSS_4);
        
        ShellSort(Copia4,TiempoSHS_4);

        HeapSort(Copia5,TiempoHS_4);

        auto start23 = chrono::high_resolution_clock::now();
        MergeSort(Copia6,0,Copia6.size() - 1);
        auto end23 = chrono::high_resolution_clock::now();
        TiempoMS_4 = chrono::duration<double>(end23 - start23).count();

        auto start24 = chrono::high_resolution_clock::now();
        QuickSort(Copia7,0,Copia7.size() - 1);
        auto end24 = chrono::high_resolution_clock::now();
        TiempoQS_4 = chrono::duration<double>(end24 - start24).count();  

        comparar(TiempoIS_4,TiempoSS_4,TiempoBS_4,TiempoSHS_4,TiempoMS_4,TiempoQS_4,TiempoHS_4);

        Ordenado.clear();
        InvOrdenado.clear();
        Aleatorio.clear();
        AlteatorioSinRepetir.clear();
    }

    return 0;
}