#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
using namespace std;

struct Ticket
{
  int number; // identity; this cannot be updated
  int date;   // data; this can be updated
};

bool operator==(const Ticket& t1, const Ticket& t2)
{
  return t1.number == t2.number && t1.date == t2.date;
}

bool ticketLess(const Ticket& s1, const Ticket& s2)
{
  if (s1.number != s2.number)
    return s1.number < s2.number;

  if (s1.date != s2.date)
    return s1.date < s2.date;

  return false;
}

bool sameIdentity(const Ticket& s1, const Ticket& s2)
{
  return (s1.number == s2.number);
}

bool sameContent(const Ticket& s1, const Ticket& s2)
{
  return (s1.date == s2.date);
}

void print(const vector<Ticket>& sv)
{
  for (Ticket s : sv)
    cout << s.number << " - " << s.date << endl;
}

void print(const vector<pair<Ticket, Ticket>>& sv)
{
  for (const pair<Ticket, Ticket>& s : sv)
    cout << "(" << s.first.number << " - " << s.first.date << ") -> (" << s.second.number << " - " << s.second.date << ")" << endl;
}

/**
 * @brief Make a diff comparison between 2 sorted sequences: from and to; store the results using added/removed/updated forward iterators
 * @note  Both input sequences must be sorted using "less" predicate mentioned below
 * @note  All the iterators need to be at least forward iterators (allowing for advancing with it++)
 * @param from  Beginning of the source sequence
 * @param fromEnd End of the source sequence
 * @param to Beginning of the destination sequence
 * @param toEnd End of the destination sequence
 * @param added Start iterator of the sequence used for storing elements detected as "added"
 * @param removed Start iterator of the sequence used for storing elements detected as "removed"
 * @param updated Start iterator of the sequence used for storing element pairs detected as "updated"
 * @param sameId Predicate used to check if two elements have the same identity
 * @param sameData Predicate used to check if two elements hold same data
 * @param less Predicate that was used to sort the from and to sequences
 */
template<class InSeqIt, class OutSeqIt, class OutSeqPairIt, class Pred>
void sortedSequencesDiff(InSeqIt from, InSeqIt fromEnd, InSeqIt to, InSeqIt toEnd, OutSeqIt added, OutSeqIt removed, OutSeqPairIt updated, Pred sameId, Pred sameData, Pred less)
{
  while (from != fromEnd || to != toEnd)
  {
    // case 1. "from" finished; the rest of "to" must have been added
    if (from == fromEnd)
    {
      copy(to, toEnd, added);
      return;
    }

    // case 2. "to" finished; the rest of "from" must have been removed
    if (to == toEnd)
    {
      copy(from, fromEnd, removed);
      return;
    }

    // case 3. same elements; there might have been an update
    if (sameId(*from, *to))
    {
      // but updated contents
      if (!sameData(*from, *to))
      {
        *updated++ = { *from, *to };
      }
      from++;
      to++;
    }

    // case 4. different elements; either add or remove must have happened and thats why different elements encountered
    else
    {
      // if "from" element is less than "to" element, then it wont be found on "to" list - removed
      if (less(*from, *to))
      {
        *removed++ = *from;
        from++; // catch up with to element
      } else
      // if "to" element is less that "from" element, then it wont be found on "from" list - added
      if (less(*to, *from))
      {
        *added++ = *to;
        to++; // catch up with from element
      }
      // equal elements are handled in case 3.
    }
  }
}

bool test(vector<Ticket> from, vector<Ticket> to, vector<Ticket> expect_add, vector<Ticket> expect_rem, vector<pair<Ticket, Ticket>> expect_upd)
{
  bool success { true };
  vector<Ticket> add, rem;
  vector<pair<Ticket, Ticket>> upd;
  sortedSequencesDiff(from.cbegin(), from.cend(), to.cbegin(), to.cend(),
      std::back_inserter(add), std::back_inserter(rem), std::back_inserter(upd),
      sameIdentity, sameContent, ticketLess);

  cout << "Test\n";
  if (add != expect_add)
  {
    cout << "add mismatch:" << endl;
    print(add);
    cout << "expected:" << endl;
    print(expect_add);
    success = false;
  }

  if (rem != expect_rem)
  {
    cout << "rem mismatch:" << endl;
    print(rem);
    cout << "expected:" << endl;
    print(expect_rem);
    success = false;
  }

  if (upd != expect_upd)
  {
    cout << "upd mismatch:" << endl;
    print(upd);
    cout << "expected:" << endl;
    print(expect_upd);
    success = false;
  }
  cout << "\n";
  return success;
}

int main()
{
  // diff empty vs empty
  test( {}, {}, {}, {}, {} );

  // diff 1 element vs same 1 element
  test( {{10, 2019}}, // from
        {{10, 2019}}, // to
        {}, // add
        {}, // rem
        {}  // upd
  );

  // diff empty vs 1 element added
  test( {}, // from
        {{10, 2019}}, // to
        {{10, 2019}}, // add
        {}, // rem
        {}  // upd
  );

  // diff non-empty vs 1 element added at the beginning
  test( {{20, 2019}}, // from
        {{10, 2019}, {20, 2019}}, // to
        {{10, 2019}}, // add
        {}, // rem
        {}  // upd
  );

  // diff non-empty vs 1 element added at the end
  test( {{10, 2019}}, // from
        {{10, 2019}, {20, 2019}}, // to
        {{20, 2019}}, // add
        {}, // rem
        {}  // upd
  );

  // diff non-empty vs 1 element removed
  test( {{10, 2019}}, // from
        {}, // to
        {}, // add
        {{10, 2019}}, // rem
        {}  // upd
  );

  // diff non-empty vs 1 element removed from the beginning
  test( {{10, 2019}, {20, 2019}}, // from
        {{20, 2019}}, // to
        {}, // add
        {{10, 2019}}, // rem
        {}  // upd
  );

  // diff non-empty vs 1 element removed from the end
  test( {{10, 2019}, {20, 2019}}, // from
        {{10, 2019}}, // to
        {}, // add
        {{20, 2019}}, // rem
        {}  // upd
  );

  // diff 1 element updated
  test( {{10, 2018}}, // from
        {{10, 2019}}, // to
        {},           // add
        {},           // rem
        {{{10, 2018} ,  {10, 2019}}} // upd
  );

  // diff following sequence of changes on subsequent elements: [nothing, add, update, remove, nothing]
  test( {{10, 2018},             {30, 2018}, {40, 2018}, {51, 2018}}, // from
        {{10, 2018}, {20, 2019}, {30, 2028},             {51, 2018}}, // to
        {{20, 2019}}, // add
        {{40, 2018}}, // rem
        {{{30, 2018} ,  {30, 2028}}}
  ); // upd

  // diff 1 element vs different element but with same data
  test( {{10, 2019}}, // from
        {{20, 2019}}, // to
        {{20, 2019}}, // add
        {{10, 2019}}, // rem
        {}  // upd
  );

  cout << "[END]" << endl;
  return 0;
}
