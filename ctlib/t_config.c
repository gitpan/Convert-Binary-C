typedef enum {
  OPTION_UnsignedChars,
  OPTION_Warnings,
  OPTION_PointerSize,
  OPTION_EnumSize,
  OPTION_IntSize,
  OPTION_ShortSize,
  OPTION_LongSize,
  OPTION_LongLongSize,
  OPTION_FloatSize,
  OPTION_DoubleSize,
  OPTION_LongDoubleSize,
  OPTION_Alignment,
  OPTION_Include,
  OPTION_Define,
  OPTION_Assert,
  OPTION_DisabledKeywords,
  OPTION_KeywordMap,
  OPTION_ByteOrder,
  OPTION_EnumType,
  OPTION_HasCPPComments,
  OPTION_HasMacroVAARGS,
  INVALID_OPTION
} ConfigOption;

static ConfigOption GetConfigOption( const char *option )
{
switch( option[0] )
{
  case 'A':
    switch( option[1] )
    {
      case 'l':
        if( option[2] == 'i' &&
            option[3] == 'g' &&
            option[4] == 'n' &&
            option[5] == 'm' &&
            option[6] == 'e' &&
            option[7] == 'n' &&
            option[8] == 't' &&
            option[9] == '\0' )
        {                                         /* Alignment  */
          return OPTION_Alignment;
        }

        goto unknown;

      case 's':
        if( option[2] == 's' &&
            option[3] == 'e' &&
            option[4] == 'r' &&
            option[5] == 't' &&
            option[6] == '\0' )
        {                                         /* Assert     */
          return OPTION_Assert;
        }

        goto unknown;

      default:
        goto unknown;
    }

  case 'B':
    if( option[1] == 'y' &&
        option[2] == 't' &&
        option[3] == 'e' &&
        option[4] == 'O' &&
        option[5] == 'r' &&
        option[6] == 'd' &&
        option[7] == 'e' &&
        option[8] == 'r' &&
        option[9] == '\0' )
    {                                             /* ByteOrder  */
      return OPTION_ByteOrder;
    }

    goto unknown;

  case 'D':
    switch( option[1] )
    {
      case 'e':
        if( option[2] == 'f' &&
            option[3] == 'i' &&
            option[4] == 'n' &&
            option[5] == 'e' &&
            option[6] == '\0' )
        {                                         /* Define     */
          return OPTION_Define;
        }

        goto unknown;

      case 'i':
        if( option[2] == 's' &&
            option[3] == 'a' &&
            option[4] == 'b' &&
            option[5] == 'l' &&
            option[6] == 'e' &&
            option[7] == 'd' &&
            option[8] == 'K' &&
            option[9] == 'e' &&
            option[10] == 'y' &&
            option[11] == 'w' &&
            option[12] == 'o' &&
            option[13] == 'r' &&
            option[14] == 'd' &&
            option[15] == 's' &&
            option[16] == '\0' )
        {                                         /* DisabledKeywords */
          return OPTION_DisabledKeywords;
        }

        goto unknown;

      case 'o':
        if( option[2] == 'u' &&
            option[3] == 'b' &&
            option[4] == 'l' &&
            option[5] == 'e' &&
            option[6] == 'S' &&
            option[7] == 'i' &&
            option[8] == 'z' &&
            option[9] == 'e' &&
            option[10] == '\0' )
        {                                         /* DoubleSize */
          return OPTION_DoubleSize;
        }

        goto unknown;

      default:
        goto unknown;
    }

  case 'E':
    switch( option[1] )
    {
      case 'n':
        switch( option[2] )
        {
          case 'u':
            switch( option[3] )
            {
              case 'm':
                switch( option[4] )
                {
                  case 'S':
                    if( option[5] == 'i' &&
                        option[6] == 'z' &&
                        option[7] == 'e' &&
                        option[8] == '\0' )
                    {                             /* EnumSize   */
                      return OPTION_EnumSize;
                    }

                    goto unknown;

                  case 'T':
                    if( option[5] == 'y' &&
                        option[6] == 'p' &&
                        option[7] == 'e' &&
                        option[8] == '\0' )
                    {                             /* EnumType   */
                      return OPTION_EnumType;
                    }

                    goto unknown;

                  default:
                    goto unknown;
                }

              default:
                goto unknown;
            }

          default:
            goto unknown;
        }

      default:
        goto unknown;
    }

  case 'F':
    if( option[1] == 'l' &&
        option[2] == 'o' &&
        option[3] == 'a' &&
        option[4] == 't' &&
        option[5] == 'S' &&
        option[6] == 'i' &&
        option[7] == 'z' &&
        option[8] == 'e' &&
        option[9] == '\0' )
    {                                             /* FloatSize  */
      return OPTION_FloatSize;
    }

    goto unknown;

  case 'H':
    switch( option[1] )
    {
      case 'a':
        switch( option[2] )
        {
          case 's':
            switch( option[3] )
            {
              case 'C':
                if( option[4] == 'P' &&
                    option[5] == 'P' &&
                    option[6] == 'C' &&
                    option[7] == 'o' &&
                    option[8] == 'm' &&
                    option[9] == 'm' &&
                    option[10] == 'e' &&
                    option[11] == 'n' &&
                    option[12] == 't' &&
                    option[13] == 's' &&
                    option[14] == '\0' )
                {                                 /* HasCPPComments */
                  return OPTION_HasCPPComments;
                }

                goto unknown;

              case 'M':
                if( option[4] == 'a' &&
                    option[5] == 'c' &&
                    option[6] == 'r' &&
                    option[7] == 'o' &&
                    option[8] == 'V' &&
                    option[9] == 'A' &&
                    option[10] == 'A' &&
                    option[11] == 'R' &&
                    option[12] == 'G' &&
                    option[13] == 'S' &&
                    option[14] == '\0' )
                {                                 /* HasMacroVAARGS */
                  return OPTION_HasMacroVAARGS;
                }

                goto unknown;

              default:
                goto unknown;
            }

          default:
            goto unknown;
        }

      default:
        goto unknown;
    }

  case 'I':
    switch( option[1] )
    {
      case 'n':
        switch( option[2] )
        {
          case 'c':
            if( option[3] == 'l' &&
                option[4] == 'u' &&
                option[5] == 'd' &&
                option[6] == 'e' &&
                option[7] == '\0' )
            {                                     /* Include    */
              return OPTION_Include;
            }

            goto unknown;

          case 't':
            if( option[3] == 'S' &&
                option[4] == 'i' &&
                option[5] == 'z' &&
                option[6] == 'e' &&
                option[7] == '\0' )
            {                                     /* IntSize    */
              return OPTION_IntSize;
            }

            goto unknown;

          default:
            goto unknown;
        }

      default:
        goto unknown;
    }

  case 'K':
    if( option[1] == 'e' &&
        option[2] == 'y' &&
        option[3] == 'w' &&
        option[4] == 'o' &&
        option[5] == 'r' &&
        option[6] == 'd' &&
        option[7] == 'M' &&
        option[8] == 'a' &&
        option[9] == 'p' &&
        option[10] == '\0' )
    {                                             /* KeywordMap */
      return OPTION_KeywordMap;
    }

    goto unknown;

  case 'L':
    switch( option[1] )
    {
      case 'o':
        switch( option[2] )
        {
          case 'n':
            switch( option[3] )
            {
              case 'g':
                switch( option[4] )
                {
                  case 'D':
                    if( option[5] == 'o' &&
                        option[6] == 'u' &&
                        option[7] == 'b' &&
                        option[8] == 'l' &&
                        option[9] == 'e' &&
                        option[10] == 'S' &&
                        option[11] == 'i' &&
                        option[12] == 'z' &&
                        option[13] == 'e' &&
                        option[14] == '\0' )
                    {                             /* LongDoubleSize */
                      return OPTION_LongDoubleSize;
                    }

                    goto unknown;

                  case 'L':
                    if( option[5] == 'o' &&
                        option[6] == 'n' &&
                        option[7] == 'g' &&
                        option[8] == 'S' &&
                        option[9] == 'i' &&
                        option[10] == 'z' &&
                        option[11] == 'e' &&
                        option[12] == '\0' )
                    {                             /* LongLongSize */
                      return OPTION_LongLongSize;
                    }

                    goto unknown;

                  case 'S':
                    if( option[5] == 'i' &&
                        option[6] == 'z' &&
                        option[7] == 'e' &&
                        option[8] == '\0' )
                    {                             /* LongSize   */
                      return OPTION_LongSize;
                    }

                    goto unknown;

                  default:
                    goto unknown;
                }

              default:
                goto unknown;
            }

          default:
            goto unknown;
        }

      default:
        goto unknown;
    }

  case 'P':
    if( option[1] == 'o' &&
        option[2] == 'i' &&
        option[3] == 'n' &&
        option[4] == 't' &&
        option[5] == 'e' &&
        option[6] == 'r' &&
        option[7] == 'S' &&
        option[8] == 'i' &&
        option[9] == 'z' &&
        option[10] == 'e' &&
        option[11] == '\0' )
    {                                             /* PointerSize */
      return OPTION_PointerSize;
    }

    goto unknown;

  case 'S':
    if( option[1] == 'h' &&
        option[2] == 'o' &&
        option[3] == 'r' &&
        option[4] == 't' &&
        option[5] == 'S' &&
        option[6] == 'i' &&
        option[7] == 'z' &&
        option[8] == 'e' &&
        option[9] == '\0' )
    {                                             /* ShortSize  */
      return OPTION_ShortSize;
    }

    goto unknown;

  case 'U':
    if( option[1] == 'n' &&
        option[2] == 's' &&
        option[3] == 'i' &&
        option[4] == 'g' &&
        option[5] == 'n' &&
        option[6] == 'e' &&
        option[7] == 'd' &&
        option[8] == 'C' &&
        option[9] == 'h' &&
        option[10] == 'a' &&
        option[11] == 'r' &&
        option[12] == 's' &&
        option[13] == '\0' )
    {                                             /* UnsignedChars */
      return OPTION_UnsignedChars;
    }

    goto unknown;

  case 'W':
    if( option[1] == 'a' &&
        option[2] == 'r' &&
        option[3] == 'n' &&
        option[4] == 'i' &&
        option[5] == 'n' &&
        option[6] == 'g' &&
        option[7] == 's' &&
        option[8] == '\0' )
    {                                             /* Warnings   */
      return OPTION_Warnings;
    }

    goto unknown;

  default:
    goto unknown;
}

unknown:
  return INVALID_OPTION;
}