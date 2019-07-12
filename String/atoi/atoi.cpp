class Solution {
public:
    int myAtoi(string str) {
        int str_len = str.length();
        int sysbol = 1;
        int start_loc = 0;
        int cal = 0;
        long temp = 0;
        int j = 0;
        while(str[j] == ' '){
            j++;
        }
        if(str[j] != '+' && str[j] != '-' && (str[j] > '9' && str[j] < '0'))
            return 0;
        else{
            if(str[j] == '+')
            {
                sysbol = 1;
                start_loc = j+1;
                if(str[start_loc] != '+' && str[start_loc] != '-' && (str[start_loc] > '9' && str[start_loc] < '0'))
                    return 0;
            }
            else if(str[j] == '-')
            {
                sysbol = -1;
                start_loc = j+1;
                if(str[start_loc] != '+' && str[start_loc] != '-' && (str[start_loc] > '9' && str[start_loc] < '0'))
                    return 0;
            }
            else{
                sysbol = 1;
                start_loc = j;
            }
        }
        for(int i = start_loc; i < str_len; i++){
            if((str[i] > '0' || str[i] == '0') && (str[i] < '9' || str[i] == '9')){
                if((sysbol * temp > LONG_MAX / 10 - (str[i] - '0') / 10 - 1) || (sysbol * temp == LONG_MAX / 10 - (str[i] - '0') / 10 - 1))
                    return INT_MAX;
                else if((sysbol * temp < LONG_MIN / 10 - (str[i] - '0') / 10 + 1) || (sysbol * temp == LONG_MAX / 10 - (str[i] - '0') / 10 + 1))
                    return INT_MIN;
                else
                    temp = temp * 10 + (str[i] - '0');
                cal = (int)temp;
            }
            else
                break;
        }


        if(sysbol > 0 && temp != cal)
            return INT_MAX;
        else if(sysbol < 0 && temp != cal)
            return INT_MIN;
        else{
            cal = cal * sysbol;
            return cal;
        }
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}