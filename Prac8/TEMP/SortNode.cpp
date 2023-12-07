using namespace std;

template <class T>
SortNode<T>::SortNode(T value)
{
    this->value = value; 
    this->next = NULL;
    this->prev = NULL;
}

template <class T>
string SortNode<T>::print()
{
    stringstream ss;
    ss << value;
    return ss.str();
}

template <class T>
T SortNode<T>::getValue()
{
    return this->value;
}

