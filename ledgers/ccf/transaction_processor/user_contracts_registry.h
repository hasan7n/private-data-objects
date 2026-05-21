/* Copyright 2026 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "ds/json.h"

using namespace std;

namespace ccf
{
  struct UserContractEntry
  {
    string contract_id;
    string contract_family;
  };

  DECLARE_JSON_TYPE(UserContractEntry);
  DECLARE_JSON_REQUIRED_FIELDS(UserContractEntry,
    contract_id,
    contract_family);

  struct Get_user_contracts {
    struct In {
      string user_verifying_key;
      string nonce;
      std::vector<uint8_t> signature;
    };

    struct Out {
      std::vector<UserContractEntry> entries;
      string signature;
    };
  };

  DECLARE_JSON_TYPE(Get_user_contracts::In);
  DECLARE_JSON_REQUIRED_FIELDS(Get_user_contracts::In,
    user_verifying_key, nonce, signature);

  DECLARE_JSON_TYPE(Get_user_contracts::Out);
  DECLARE_JSON_REQUIRED_FIELDS(Get_user_contracts::Out, entries, signature);
}
