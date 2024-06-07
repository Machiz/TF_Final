class HashEntidad
{
private:
	int key;
	int value;
public:
	HashEntidad(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
	int getkey() { return key; }
	int getvalue() { return value; }
};

