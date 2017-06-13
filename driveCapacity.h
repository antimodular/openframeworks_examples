//
//  driveCapacity.h
//  faceSplitting_v3_intermix_primary
//
//  Created by Stephan Schulz on 2017-01-19.
//
//

#ifndef driveCapacity_h
#define driveCapacity_h

class driveCapacity{
public:
    
    bool checkCapacity(int maxUsed){
        //maxUsed should be determined by user
        //how  much of the hard drive space in % should be use up
        
        bool tooFull;
        
        string mySysInfo = myExec("df -H /Volumes");
        cout<<"mySysInfo "<<mySysInfo<<endl;
        int pos = mySysInfo.find("% ");
        //cout<<"pos "<<pos<<endl;
        string myCapacityStr = mySysInfo.substr(pos-3,pos-1);
        //cout<<"myCapacityStr "<<myCapacityStr<<endl;
        int myCapacityInt = ofToInt(myCapacityStr);
        
        if(myCapacityInt >= maxUsed) tooFull = true;
        else tooFull = false;
        
        cout<<"used capacity % = "<<myCapacityInt<<", tooFull = "<<tooFull<<endl;
        return tooFull;
    }
    
    
    
    string myExec(char* cmd) {
        FILE* pipe = popen(cmd, "r");
        if (!pipe) return "ERROR";
        char buffer[128];
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        return result;
    }

};
#endif /* driveCapacity_h */
