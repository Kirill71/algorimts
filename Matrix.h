/*
	2018

	Author : Kirill Zharenkov, Aldec-KTC Team.

	Date: 01.11.2017

	Purpose: class for representation mathematic matrix.

	All right reserved (c).

*/

/*---------------------------------------------------------------------------*/

#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

/*---------------------------------------------------------------------------*/

#include <vector>
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <iostream>



/*---------------------------------------------------------------------------*/

class Matrix
{

public:

/*---------------------------------------------------------------------------*/

    using MatrixDataType = double;

    using Row = std::vector< MatrixDataType >;
    using Column = std::vector< MatrixDataType >;

/*---------------------------------------------------------------------------*/

private:

/*---------------------------------------------------------------------------*/

    using MatrixImpl = std::vector< std::vector< MatrixDataType > >;

    using MatrixImplPtr = std::unique_ptr< MatrixImpl >;

/*---------------------------------------------------------------------------*/

public:

/*---------------------------------------------------------------------------*/

    Matrix() = delete;
    Matrix( unsigned _rowSize, unsigned _collSize );
    Matrix(
            unsigned _rowSize
            ,	unsigned _collSize
            ,	std::initializer_list<MatrixDataType > _list
    );

    Matrix( const Matrix& _matrix );
    Matrix& operator= ( const Matrix& _matrix );


    Matrix( const Matrix&& _matrix );
    Matrix& operator= (const Matrix&& _matrix ) = delete;

    ~Matrix() = default;

/*---------------------------------------------------------------------------*/

    auto begin() noexcept  { return m_matrix->begin(); }
    auto end() noexcept { return m_matrix->end(); }

    auto cbegin() const noexcept  { return m_matrix->cbegin(); }
    auto cend()  const noexcept { return m_matrix->cend(); }

    auto rbegin() noexcept { return m_matrix->rbegin(); }
    auto rend() noexcept { return m_matrix->rend(); }

    auto crbegin()  const noexcept  { return m_matrix->crbegin(); }
    auto crend() const  noexcept { return m_matrix->crend(); }

    size_t rowSize()  const noexcept { return m_rowSize; }
    size_t collSize() const noexcept { return  m_collSize; }

    bool empty() const noexcept { return m_matrix->empty(); }

    void insertRow( const Row& _row );
    void insertColumn( const Column& _column );

    const Row& operator[] ( unsigned _index ) const;
    Row& operator[] ( unsigned _index );

    void clear();

/*---------------------------------------------------------------------------*/

private:

/*---------------------------------------------------------------------------*/

    friend Row operator+ ( const Row& _lhs, const Row& _rhs );
    friend Row operator* ( const Row& _row, const MatrixDataType _scalar );

    friend  std::ostream& operator<< ( std::ostream& _ostream, const Matrix& _matrix );
    friend  const std::istream& operator>> ( std::istream& _istream, Matrix& _matrix );

    auto makeMatrixImpl( unsigned _rowSize )   const  noexcept;

/*---------------------------------------------------------------------------*/

    size_t  m_rowSize;
    size_t  m_collSize;

    MatrixImplPtr m_matrix;

/*---------------------------------------------------------------------------*/

}; // class Matrix

/*---------------------------------------------------------------------------*/

#endif // !_MATRIX_HPP_