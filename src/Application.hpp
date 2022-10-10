// #pragma once

// #include "Candidate.hpp"
// #include "CandidatesValidator.hpp"
// #include <vector>
// #include <memory>
// #include <algorithm>

// std::vector<Candidate> getFilteredCandidates(const std::vector<Candidate>& candidates,
//                                              std::unique_ptr<CandidatesValidator> requirements)
// {
//     std::vector<Candidate> qualified;
//     std::copy_if(candidates.begin(), candidates.end(), std::back_inserter(qualified),
//                  [&](Candidate c)
//                  {
//                      return requirements->shouldBeHired(c);
//                  });
//     return qualified;
// }
