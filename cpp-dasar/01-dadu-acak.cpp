#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    
    char lanjut;
    while(true){
        cout << "Lempar dadu? (y/n)";
        cin >> lanjut;

        if(lanjut == 'y'){
            cout << 1 + (rand() % 6) << endl;
        }else if(lanjut == 'n'){
            break;
        }else{
            cout << "warning: ketik y atau n\n";
        }
    }
}