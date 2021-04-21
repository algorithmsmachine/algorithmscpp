using System;
using System.Collections.Generic;
using System.Linq;

namespace SQLCommandPattern{

public enum BinaryOperation    {
        Equals,
        NotEquals,
        GreaterThan,
        GreaterThanOrEquals,
        LessThan,
        LessThanOrEquals,
        In,
        Like,
        IsNull
    }
    public interface IPredicate    {
        string ColumnName { get; }
        BinaryOperation Operation { get; }
        object Value { get; }
    }

    public interface IQueryManager    {
    // issues a SQL INSERT operation for tableName setting the provided column values
    //
    // an IDictionary<string, object> is an interface  that maps string keys onto object values,
    // for java developers think Map<String, Object> and for javascript/typescript developers think 'hash'
    IQuery Insert(string tableName, IDictionary<string, object> columnValues);

    // issues a SQL UPDATE operation for tableName setting the provided column values and creating a WHERE clause
    // from the predicates
    //
    // an IList<IPredicate> is an order list of predicate objects.
    // java developers can think of IList much like ArrayList and an IDictionary as a Map, if that helps
    IQuery Update(string tableName, IDictionary<string, object> columnValues, IList<IPredicate> predicates);

    // issues a SQL DELETE operation for tableName with a WHERE clause from the predicates
    IQuery Delete(string tableName, IList<IPredicate> predicates);

    // causes the requested database operations to
    // execute (returns true if at least one row is effected),
    // check the individual IQuery returns from the above
    // methods to determine the actual impact of each
    bool Commit();
    // abandons the requested database operations
    // (returns false if there are no operations)
    bool Rollback();
}

public interface IConnection    {
    void BeginTransaction();
    void Commit();
    void Rollback();
    void Execute(string sqlStatement);
}

// dummy interface
public interface IQuery    {
        bool Execute(IConnection connection);
}

// this is our base command object that knows how to
// execute itself, but doesn't know how to build
// itself given its stored parameters
public abstract class BaseCommand : IQuery    {
    public bool Execute(IConnection connection)        {
        return connection.Execute(BuildStatement());
    }

    protected virtual string BuildStatement();
}

// an insert command object that holds the table and column values
public class InsertCommand : IQuery    {
    private readonly string tableName;
    private readonly IDictionary<string, object> columnValues;
    public InsertCommand(string tableName, IDictionary<string, object> columnValues)        {
        this.tableName = tableName;
        this.columnValues = columnValues;
    }
    protected override string BuildStatement(IConnection connection)        {
        // create the insert statement and execute the command
        return "INSERT INTO ...";
    }
}

// an update command that holds the table,
public class UpdateCommand : IQuery    {
    private readonly string tableName;
    private readonly IDictionary<string, object> columnValues;
    private readonly IList<IPredicate> predicates;
    public UpdateCommand(string tableName,IDictionary<string, object> columnValues,  IList<IPredicate> predicates)        {
        this.tableName = tableName;
        this.columnValues = columnValues;
        this.predicates = predicates;
    }

    protected override string BuildStatement(IConnection connection)        {
    // create the update statement and execute the command
        return "UPDATE ... WHERE ...";
    }
}

public class DeleteCommand : IQuery    {
    private readonly string tableName;
    private readonly IList<IPredicate> predicates;
    public DeleteCommand(string tableName, IList<IPredicate> predicates)        {
        this.tableName = tableName;
        this.columnValues = columnValues;
    }

    protected override string BuildStatement()        {
        // create the delete statement and execute the command
        return "DELETE ... WHERE ...";
    }
}

public class QueryManager : IQueryManager    {
// this is our ordered sequence of operations
    private readonly IList<IQuery> commands = new List<IQuery>();
    // our database connection
    private readonly IConnection connection;
    // constructor to hang onto the database connection
    public QueryManager(IConnection connection)        {
        this.connection = connection;
    }
    // add the insert command
    public IQuery Insert(string tableName, IDictionary<string, object> columnValues) {
            commands.Add(new InsertCommand(tableName, columnValues));
    }

    // add the update command
    public IQuery Update(string tableName, IDictionary<string, object> columnValues, IList<IPredicate> predicates)        {
        commands.Add(new UpdateCommand(tableName, predicates));
    }

    // add the delete command
    public IQuery Delete(string tableName, IList<IPredicate> predicates)        {
        commands.Add(new DeleteCommand(tableName, predicates));
    }

    // do actual work by iterating and executing the commands
    public bool Commit()        {
        connection.BeginTransaction();
        foreach (var command in commands)            {
            if (command.Execute(connection) == false) {
            // rollback any database work
            connection.Rollback();
            // clear our command list
            commands.Clear();
            return false;
        }
    }
    connection.Commit();
    return true;
    }

    // no real work to do here, just clear the command list
    public bool Rollback()        {
        commands.Clear();
    }
}
}
