#include "proteincollection.h"
#include <map>
#include "protein.h"


ProteinCollection::ProteinCollection(): _protein_map(){}

const std::map<std::string, Protein>& ProteinCollection::getProteinList() const
{
    return _protein_map;
}

bool ProteinCollection::addProtein(const std::string& name,const Protein& protein, int key)
{
    auto i = _protein_map.find(name);
    if (i != _protein_map.end()){
        if (key){
            _protein_map[name] = Protein(protein);
        }
        return false;
    }
   _protein_map[name] = protein;
   //int q =0;
   return true;
}


ProteinCollection& ProteinCollection::getInstance()
{
    static ProteinCollection p;
    return p;
}


void ProteinCollection::addAminoAcid(const std::string& protein_name, const std::string& acid_name, const std::string& acid_short_name,
                                     bool in_the_beginning, bool in_the_end, const int position)
{
    Acid* new_acid = new Acid(acid_name, acid_short_name);
    if (in_the_beginning) {
         _protein_map[protein_name].AddHead(*new_acid);
    } else if (in_the_end) {
        _protein_map[protein_name].AddTail(*new_acid);
    } else {
        _protein_map[protein_name].Insert(position, *new_acid);
    }
    delete new_acid;
}


void ProteinCollection::deleteProtein(const std::string& name)
{
    _protein_map.erase(name);
}


void ProteinCollection::deleteAminoAcid(const std::string& name, bool from_begin){
    if (from_begin){
        _protein_map[name].Del(1);
    }
    else{
        _protein_map[name].Del(_protein_map[name].GetCount());
    }
}


void ProteinCollection::deleteAminoAcidFromPos(const std::string& name, const int position)
{
    _protein_map[name].Del(position);
}


void ProteinCollection::clearProtein(const std::string& name)
{
    _protein_map[name].DelAll();
}


int ProteinCollection::countAcidInProtein(const std::string& name)
{
    return _protein_map[name].GetCount();
}
