class account_query
{
private:
    int m_record_no = 0;
    char m_account_number[20];
    char m_firstName[10];
    char m_lastName[10];
    float m_total_Balance;
public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
};
