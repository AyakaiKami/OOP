#include <iostream>

template<typename V, typename K>
class Map
{
private:
public:
    struct Nod
    {
        K key;
        V value;
        int index;
        void operator=(const K& key_in)
        {
            this->key= key_in;
            printf("%s %d %d\n", key, value, index);
        }
    };
    Nod* map;
    int size;
//
    Map() { map = new Nod[1]; size = 0; }
    ~Map() { delete[] map; }
    Nod& operator[](V value_in) 
    {
        for (int i = 0; i < size; i++)
            if (map[i].value == value_in)
                return map[i];
        size++;
        map[size-1].value = value_in;
        map[size-1].index = size;
        map[size - 1].key = "here";
        Grow();
        return map[size-1];
    }
    void Grow()
    {
        Nod* cop = map;
        map = new Nod[size + 1];
        for (int i = 0; i <size; i++)
            map[i] = cop[i];
        delete[] cop;
    }
    bool Get(const K& key_in, V& value_in)
    {
        for(int i=0;i<size;i++)
            if (map[i].key == key_in)
            {
                value_in = map[i].value;
                return 1;
            }

    }
    void Set(K key_in, V value_in)
    {
        bool ok = false;
        for (int i = 0; i < size; i++)
            if (map[i].key == key_in)
            {
                map[i].value = value_in; ok = true;
            }
        if (ok == false)
        {
            size++;
            map[size-1].key = key_in;
            map[size-1].value = value_in;
            map[size-1].index = size ;
            Grow();
        }
    }
    int Count() {
        return size;
    }
    void Clear()
    {
        map = new Nod[1]; size = 0;
    }
    bool Delete(const K& key_in)
    {
        bool ok = false;
        int i;
        for(i=0;i<size;i++)
            if (key_in == map[i].key)
            {
                ok = true; break;
            }
        if (ok == true)
        {
            Nod* cop = map;
            map = new Nod[size - 1];
            for (int j = 0; j < i; j++)
                map[j] = cop[j];
            for (int j = i; j < size-1; j++)
                map[j] = cop[j + 1];
            delete cop;
            return ok;
        }
        return ok;
    }
    Nod* begin() { return &map[0]; }
    Nod* end() { return &map[Count() ]; }
    bool Includes(const Map <K,V>& map_in )
    {
        if (Count() < map_in.size)
            return false;
        for (auto [key1, value1, index1] : this.map)
        {
            bool ok = false;
            for (auto [value2, key2, index2] : map_in)
                if (value1 == value2 && key1 == key2)
                    ok = true;
            if (ok == false)
                return true;
        }
        return true;
    }
};

int main() 
{
    Map<int, const char*> m;   
    Map<const char*, int>rev;
    rev.Set(10, "C++");
    m[10] = "C++";    
    m[20] = "test";    
    m[30] = "Poo";    
    printf("%b\n", m.Includes(rev));
    for (auto [key, value, index] : m) 
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value); 
    } 
    m[20] = "result";  
    for (auto [key, value, index] : m) 
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }    
    return 0;
}