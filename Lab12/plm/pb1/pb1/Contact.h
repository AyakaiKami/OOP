#ifndef CONTACT
#define CONTACT
#include <iostream>
#include <vector>
class Contact
{
protected:
	std::string nume;
public:
	Contact(void){}
	Contact(std::string input)
	{
		this->nume = input;
	}
	std::string GetNume()
	{
		return this->nume;
	}
	virtual std::string GetTip() = 0;
};

class Prieten :public Contact 
{
private:
	std::string data_nastere;
	std::string adresa;
	std::string nr_telefon;
public:
	Prieten(std::string in_nume,std::string in_dn,std::string in_adr,std::string in_nrtel )
	{
		this->nume = in_nume;
		this->data_nastere = in_dn;
		this->adresa = in_adr;
		this->nr_telefon = in_nrtel;
	}
	std::string GetAdresa() 
	{
		return this->adresa;
	}
	std::string GetDataNastere()
	{
		return this->data_nastere;
	}
	std::string GetNrTelefon()
	{
		return this->nr_telefon;
	}
	std::string GetTip()override
	{
		std::string tip = "Prieten";
		return tip;
	}
};

class Cunoscut :public Contact
{
private:
	std::string nr_telefon;
public:
	Cunoscut(std::string in_nume, std::string in_nrtel)
	{
		this->nume = in_nume;
		this->nr_telefon = in_nrtel;
	}
	std::string GetNrTelefon()
	{
		return this->nr_telefon;
	}
	std::string GetTip()override
	{
		std::string tip = "Cunoscut";
		return tip;
	}
};

class Coleg :public Contact
{
private:
	std::string serviciu;
	std::string adresa;
	std::string nr_telefon;
public:
	Coleg(std::string in_nume, std::string in_adr, std::string int_nrtel)
	{
		this->nume = in_nume;
		this->adresa = in_adr;
		this->nr_telefon = int_nrtel;
	}
	std::string GetServiciu()
	{
		return this->serviciu;
	}
	std::string GetNrTelefon()
	{
		return this->nr_telefon;
	}
	std::string GetAdresa()
	{
		return this->adresa;
	}
	std::string GetTip()override
	{
		std::string tip = "Coleg";
		return tip;
	}
};

class Agenda
{
private:
	std::vector<Contact*> contacte;
public:
	void Show()
	{
		for (int i = 0; i < this->contacte.size(); i++)
				std::cout << this->contacte[i]->GetNume()<<'\n';
	}
	Contact* Cauta(std::string nume) 
	{
		for (int i = 0; i < this->contacte.size(); i++)
			if (this->contacte[i]->GetNume() == nume)
				return this->contacte[i];
		return nullptr;
	}
	std::vector<Contact*> GetPrieteni()
	{
		std::vector<Contact*> Prieteni;
		std::string tip = "Prieten";
		for (int i = 0; i < this->contacte.size(); i++)
			if (this->contacte[i]->GetTip() == tip)
				Prieteni.push_back(this->contacte[i]);
		return Prieteni;
	}
	void Sterge(std::string name)
	{
		for (int i = 0; i < this->contacte.size(); i++)
			if (this->contacte[i]->GetNume() == name)
				for (int j = i; j < this->contacte.size()-1; j++)
					this->contacte[j] = this->contacte[j + 1];
		this->contacte.resize(this->contacte.size() - 1);
	}
	void Adauga(Contact* input)
	{
		this->contacte.push_back(input);
	}
};




#endif // !Contact
