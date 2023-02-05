// Robi Gurung
// sequence_map.h : Header/Declaration file to simulate a biological structure.

#include <vector>
#include <string>
#include <ostream>
using namespace std;

class SequenceMap {
    public:
        // Zero-parameter constructor. 
        SequenceMap() : recognition_sequence_{""} 
        {}

        // Copy-constructor.
        SequenceMap(const SequenceMap &rhs) {
            recognition_sequence_ = rhs.recognition_sequence_;
            for(size_t i=0; i<rhs.enzyme_acronyms_.size(); i++)
                enzyme_acronyms_.push_back(rhs.enzyme_acronyms_[i]);
        }

        // Copy-assignment.
        SequenceMap& operator=(const SequenceMap &rhs) {
            enzyme_acronyms_.clear();
            recognition_sequence_ = rhs.recognition_sequence_;
            for(size_t i=0; i<rhs.enzyme_acronyms_.size(); ++i)
                enzyme_acronyms_.push_back(rhs.enzyme_acronyms_[i]);
            return *this;
        }
        
        // Move-constructor. 
        SequenceMap(SequenceMap &&rhs)
        {
            recognition_sequence_ = rhs.recognition_sequence_;
            enzyme_acronyms_ = std::move(rhs.enzyme_acronyms_);
        }
        
        // Move-assignment.
        SequenceMap& operator=(SequenceMap &&rhs) {
            std::swap(recognition_sequence_, rhs.recognition_sequence_);
            std::swap(enzyme_acronyms_, rhs.enzyme_acronyms_);
            return *this;
        }

        // constructs a SequenceMap from two strings
        SequenceMap(const string &a_rec_seq, const string &an_enz_acro) {
            recognition_sequence_ = a_rec_seq;
            enzyme_acronyms_.push_back(an_enz_acro);
        }

        // Deconstructor
        ~SequenceMap() {
            recognition_sequence_ = "";
            enzyme_acronyms_.clear();
        }

        // operates based on the regular string comparison between 
        // the recognition_sequence_ strings
        bool operator<(const SequenceMap &rhs) const {
            return (recognition_sequence_.compare(rhs.recognition_sequence_) < 0);
        }

        bool isEmpty() const {
            return recognition_sequence_.empty();
        }

    // puts all the enzyme acronyms into the output stream 
    friend ostream &operator<<(std::ostream &output, const SequenceMap &some_map) {
        // output << some_map.recognition_sequence_ << std::endl;
        if (some_map.enzyme_acronyms_.size() == 0)
            output << "Not Found";
        for(size_t i = 0; i < some_map.enzyme_acronyms_.size(); ++i)
        {		
            output << some_map.enzyme_acronyms_[i] << " ";
        }
        output << std::endl;
        return output;
    }

    // This function assumes that the object’s recognition_sequence_ and 
    // other_sequence.recognition_sequence_ are equal to each other. The 
    // function Merge() merges the other_sequence.enzyme_acronym_ with the 
    // object’s enzyme_acronym_. The other_sequence object will not be affected.
    void Merge(const SequenceMap &other_sequence) {
        for(size_t i = 0; i < other_sequence.enzyme_acronyms_.size(); ++i)
        {		
            enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
        }
    }
    
    private:
        string recognition_sequence_ ; 
        vector<string> enzyme_acronyms_; 
};