using namespace std;
namespace olivia
{
    Bankacct::Bankacct(std::string o, double bal, double ir)
    {
        ownerid = o;
        balance = bal;
        intrestRate = ir;
    }

    void Bankacct::input(std::istream& ins)
    {
        cout << "Enter the owner id: ";
        ins >> ownerid;
    }

    void bankacct::output(ostream& outs)
    {
        if (&outs == &cout) // Checks if the stream is cout and not a file before prompting
        {
            outs << "Ownerid: " << ownerid << endl;
        }
        else
        {
            outs<< ownerid << endl;
        }
    }

    std::istream& operator >> (std::istream& ins, Bankacct& b1)
    {
        b1.input(ins);
        return ins;
    }
    std::ostream& operator << (std::ostream& outs, const Bankacct&  b1)
    {
        b1.output(outs);
        return outs;
    }

    // Friend implementation
    /*
    Bankacct operator +(const bankacct& b1, const bankacct& b2)
    {
        Bankacct temp;
        temp.ownerid = b1.ownerid + " " + b2.ownerid;
        temp.balance = b1.balance + b2.balance;
        temp.intrestRate = (b1.intrestRate + b2.intrestRate) / 2.0;

        return temp;
    }
    */

    Bankacct Bankacct::operator +(const bankacct& b2)
    {
        Bankacct temp;
        temp.ownerid = ownerid + " " + b2.ownerid;
        temp.balance = balance + b2.balance;
        temp.intrestRate = (intrestRate + b2.intrestRate) / 2.0;

        return temp;
    }

} // End of olivia namespace