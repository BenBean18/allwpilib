/*
 * ITableListener.h
 */

#ifndef ITABLELISTENER_H_
#define ITABLELISTENER_H_

#include <memory>

#include "tables/ITable.h"

/**
 * A listener that listens to changes in values in a {@link ITable}
 */
class ITableListener {
 public:
  virtual ~ITableListener() = default;
  /**
   * Called when a key-value pair is changed in a {@link ITable}
   * WARNING: If a new key-value is put in this method value changed will
   * immediatly be called which could lead to recursive code
   * @param source the table the key-value pair exists in
   * @param key the key associated with the value that changed
   * @param value the new value
   * @param isNew true if the key did not previously exist in the table,
   * otherwise it is false
   */
  virtual void ValueChanged(ITable* source,
                            llvm::StringRef key,
                            std::shared_ptr<nt::Value> value, bool isNew) = 0;
};

#endif /* ITABLELISTENER_H_ */
