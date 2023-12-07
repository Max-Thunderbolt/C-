
using namespace std;

template <class T>
SortNode<T> :: SortNode(T val){

    value = val;

}

template <class T>
std::string SortNode<T> ::print(){
    stringstream ss;
    ss<<this->value;
    string out;
    ss>>out;
    return out;
}

template <class T>
T SortNode<T> ::getValue(){
    return (value);
}
