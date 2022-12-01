namespace rod
{
    // Will fill the container with the value passed.
    template <typename CONTAINER>
    bool fill(const CONTAINER &container, auto value){
        try{
            for(auto i = container.begin(); i != container.end(); i++){
                *i = value;
            }
        }catch(...){
            return false;
        }
        return true;
    }
}
