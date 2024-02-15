template <typename T>
class vector
{
    // accessor functions and so forth
    private:
    T* vec_data;   // we'll store the data as block of dynamically allocated 
                   // memory
    int length;    // number of elements used 
    int vec_size;  // actual size of vec_data
};