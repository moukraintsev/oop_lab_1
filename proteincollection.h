#ifndef PROTEINCOLLECTION_H
#define PROTEINCOLLECTION_H

#include <iostream>
#include <map>
#include "protein.h"


class ProteinCollection
{
public:
    static ProteinCollection& getInstance();
    const std::map<std::string, Protein>& getProteinList() const;
    bool addProtein(const std::string&, const Protein&, int=0);
    void addAminoAcid(const std::string&, const std::string&, const std::string&, bool, bool, const int);
    void deleteAminoAcid(const std::string&, bool);
    void deleteAminoAcidFromPos(const std::string&, const int);
    void deleteProtein(const std::string&);
    void clearProtein(const std::string&);
    int countAcidInProtein(const std::string&);
private:
    ProteinCollection();
    ProteinCollection(const ProteinCollection&) = delete;
    ProteinCollection& operator=(ProteinCollection&) = delete;
    ~ProteinCollection(){};
    std::map<std::string, Protein> _protein_map;
};


#endif // PROTEINCOLLECTION_H
