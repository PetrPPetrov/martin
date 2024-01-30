// ResultLexemSet.h: interface for the CResultLexemSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESULTLEXEMSET_H__FB38BEE3_527D_4428_8048_41C145B142FD__INCLUDED_)
#define AFX_RESULTLEXEMSET_H__FB38BEE3_527D_4428_8048_41C145B142FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

class CResultLexemSet  
{
public:
	CResultLexemSet();
	virtual ~CResultLexemSet();
	void AddLexem(int,std::string&,std::string&,long,std::string&);
	void AddLexem(CResultLexem&);
	void Dump(std::string);

	void GetNextLexem(CResultLexem&,bool);
	void Prepare();
	void Reset();

	friend std::ofstream& operator<<(std::ofstream&,CResultLexemSet&);
private:
	std::vector<CResultLexem*> m_vLexems;
	std::vector<CResultLexem*>::iterator m_itCur;
};

__PETER_COMPILER_END

#endif // !defined(AFX_RESULTLEXEMSET_H__FB38BEE3_527D_4428_8048_41C145B142FD__INCLUDED_)
