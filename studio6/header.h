
class MyStruct {
    private:
        int x;
        int y;
    
    public:
        MyStruct();

        //copy constructor
        MyStruct(const MyStruct& other);

        //accessor
        int getX() const;
        int getY() const;

        //mutator
        MyStruct& setX(int value);
        MyStruct& setY(int value);

        MyStruct passAndReturnByValue(MyStruct obj);

};

