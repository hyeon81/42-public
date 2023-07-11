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
            arr = new T[0];
        }
        Array(unsigned int n) {
            arr = new T[n];
            len = n;
        }
        Array(const Array &obj) {
            this->len = obj.len;
            arr = new T[this->len];
            for (unsigned int i = 0; i < len; i++)
                this->arr[i] = obj.arr[i];
        }
        Array &operator=(const Array &obj) {
            if (this != &obj) {
                this->len = obj.len;
                delete []arr;
                arr = new T[this->len];
                for (unsigned int i = 0; i < len; i++)
                    this->arr[i] = obj.arr[i];
            }
            return (*this);
        }
        ~Array() {
            delete[] arr;
        }
        T& operator[] (unsigned int idx) const { 
            if (idx > len - 1)
                throw std::out_of_range("out of range");
            return (this->arr[idx]);
        }

        const T& operator[] (unsigned int idx) const{ 
            if (idx > len - 1)
                throw std::out_of_range("out of range");
            return (this->arr[idx]);
        }

        unsigned int size() {
            return (this->len);
        }
};

#endif