#include <iostream>
#include <stdexcept>
#include <string>

class Array{
    public:
        class Proxy{
            private:
                int& element;

            public:
                Proxy(int& dataElement):element(dataElement){}

                operator int() const {
                    return this->element;
                }

                int& operator=(const int& value){
                    this->element = value;
                    return this->element;
                }
        };

    private:
        int* data;
        size_t size;

    public:
        Array(int arraySize){
            if(arraySize > 0){
                this->size = arraySize;
                this->data = new int[arraySize]{};
            } else{
                throw std::invalid_argument("size harus lebih besar dari nol");
            }
        }

        Array(std::initializer_list<int> list){
            this->size = list.size();
            this->data = new int[this->size];
            int i = 0;
            for (auto value:list){
                this->data[i++] = value;
            }
        }

        ~Array(){
            delete[] data;
        }

        Proxy operator[](int index){
            if(index < 0 || index >= this->size){
                throw std::out_of_range("index kelebihan");
            }
            return Proxy(this->data[index]);
        }

        int getSize() const{
            return this->size;
        }

        friend std::ostream& operator<<(std::ostream& os, Array& arr){
            os << "[";
            for (size_t i = 0; i < arr.size; i++){
                os << arr[i];
                if (i < arr.size - 1){
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        bool operator==(const Array& otherArray) const{
            return true;
        }
};

int main(int argc, char const *argv[])
{
    Array data_array(5);
    Array data_array2 = {0,1,2,3,4,5,6};
    

    data_array[0] = 5;
    data_array[1] = 6;
    std::cout << data_array[0] << std::endl;
    std::cout << data_array[1] << std::endl;
    std::cout << data_array.getSize() << std::endl;

    std::cout << "data array 2" << std::endl;
    std::cout << data_array2[1] << std::endl;
    std::cout << data_array2.getSize() << std::endl;

    std::cout << data_array << std::endl;
    std::cout << data_array2 << std::endl;

    std::cout << (data_array == data_array2) << std::endl;

    return 0;
}