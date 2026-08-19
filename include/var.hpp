#ifndef VAR
#define VAR

class Var {
	public:
		std::string type;
		std::string name;
		std::string value;

		Var(std::string t, std::string n, std::string v) {
			type = t;
			name = n;
			value = v;
		}

		std::string toString() {
			return type + " " + name + ":" + value;
		}
};

#endif // VAR
