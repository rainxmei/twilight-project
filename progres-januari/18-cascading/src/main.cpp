#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string nama_depan;
        string nama_tengah;
        string nama_belakang;

    public: 
        Player(){
            nama_depan = "depan"; // menggunakan teknik implicit
            this->nama_tengah = "tengah"; // teknik explicit dengan menggunakan pointer arrow
            // Player::nama_belakang = "belakang"; // teknik explicit
            (*this).nama_belakang = "belakang"; // dereference this pointer dan dot operator
        }

        // kita bisa melakukan cascade function calls dengan *this
        Player& setNamaDepan(const char* depan){
            this->nama_depan = depan;
            return *this;
        }

        Player& setNamaBelakang(const char* belakang){
            (*this).nama_belakang = belakang;
            return *this;
        }

        Player& setNamaTengah(const char* tengah){
            this->nama_tengah = tengah;
            return *this;
        }

        void display(){
            cout << "Nama:";
            cout << " " << nama_depan;
            cout << " " << this->nama_tengah;
            cout << " " << (*this).nama_belakang << endl;
        }
};

int main(int argc, char const *argv[])
{
    Player* player1 = new Player();
    player1->display();
    
    player1->setNamaDepan("abyan");
    player1->setNamaBelakang("muhammad");
    player1->setNamaTengah("keane");
    player1->display();

    // cascade function calls
    player1->setNamaDepan("heru").setNamaTengah("muna").setNamaBelakang("sugeng");
    player1->display();

    Player player2 = Player();
    player2.display();
    player2.setNamaTengah("haha").setNamaDepan("hihi").setNamaBelakang("hoho");
    player2.display();

    return 0;
}