#include <iostream>
#include "Matrix.h"



const Matrix& transform( Matrix& _matrix )
{

    auto logic = []( auto& _matrix ) -> const Matrix&
    {
        for (size_t i = 0; i < _matrix.rowSize(); ++i )
            for (size_t j = 0; j < _matrix.collSize(); ++j )
                if ( i < j )
                    std::swap(_matrix[j][i], _matrix[i][j]);

        return _matrix;
    };

    if ( _matrix.rowSize() == _matrix.collSize() )
        return logic(_matrix );


}

int main() {
    Matrix m(2,3,{1,2,3,4,5,6} );

    std::cout << transform( m );
}