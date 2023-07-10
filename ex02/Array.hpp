#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array 
{
    private:
        T *arr;
        unsigned int len;
    public:
        Array() {
            arr = new T[0]; //이게 빈배열인가?
        }
        Array(unsigned int n) {
            arr = new T[n];
        }
        Array(const Array &obj) {
            this->len = obj.len;
            if (arr)
                delete[] arr;
            *(this->arr) = *(obj.arr);
        }
        Array &operator=(const Array &obj) {
            if (this != &obj) {
                this->len = obj.len;
                if (arr)
                    delete[] arr;
                *(this->arr) = *(obj.arr);
            }
            return (*this);
        }
        ~Array() {
            delete[] arr; //이렇게 없애줘야하나?
        }
        T& operator[] (unsigned int idx) {
            if (idx > len - 1)
                throw std::out_of_range("out of range");
            return (this->arr[idx]);
        }
        unsigned int size() {
            return (this->len);
        }
};

#endif