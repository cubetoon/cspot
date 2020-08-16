
#ifndef MERCURYRESPONSE_H
#define MERCURYRESPONSE_H

#include <map>
#include <string>
#include <functional>
#include <vector>
#include "mercury.pb.h"
#include "PBUtils.h"
#include "Utils.h"

typedef std::vector<std::vector<uint8_t>> mercuryParts;

class MercuryResponse
{
private:
    void parseResponse(std::vector<uint8_t> &response);
public:
    MercuryResponse(std::vector<uint8_t> &data);
    Header mercuryHeader;
    mercuryParts parts;
    int64_t sequenceId;
};

#endif