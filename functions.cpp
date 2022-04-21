class Actor{
    public:
    string theName;
    int theAppearances;
};

void add_actor(vector<string> list, vector<Actor> & inputs){
    Actor adding;
    int location = -1;
    //You're given a list of all the actors in appearances in "list", now you add them to "inputs"
    //Look through "list", while getting the string (being the name)
    for(int i = 0; i < list.size(); i++){
        //Go Through the entire "inputs" and its "theName"
        for (int j = 0; j < inputs.size(); j++){
            if (list.at(i) == inputs.at(j).theName){
                location = j;
            }
        }
        //If it appears, increase "theAppearances" by 1
        if (location != -1){
            inputs.at(location).theAppearances++;
        }
        //If it doesn't, add a new one there with "theAppearances" being 1
        else{
            adding.theAppearances = 1;
            adding.theName = list.at(i);
            inputs.push_back(adding);
        }
        location = -1;
    }
}

void order(vector<Actor> inputs) {
    vector<Actor> results;
    Actor helping;
    int highest = -1;
    int position = -1;
    for(int i = 0; i < inputs.size(); i++){
        int highest = -1;
        for(int j = 0; j < inputs.size(); j++){
            if (inputs.at(j).theAppearances > highest){
                highest = inputs.at(j).theAppearances;
                position = j;
            }
        }
        helping.theAppearances = highest;
        helping.theName = inputs.at(position).theName;
        results.push_back(helping);
        inputs.at(position).theAppearances = -1;
        highest = -1;
        position = -1;
    }
    //only used to show the code's working
    for (int i = 0; i < results.size(); i++){
        cout << "The name is " << results.at(i).theName;
        cout << " and their appearances are " << results.at(i).theAppearances << endl;
    }
}
